#include "webp.h"
#include <stdlib.h>
#include <stdio.h>

#include <webp/decode.h>

#define LOG_MODULE "webp"
#define LOG_ENABLE_DBG 0
#include "log.h"
#include "stride.h"

pixman_image_t *
webp_load(FILE *fp, const char *path)
{
    uint8_t *file_data = NULL;
    uint8_t *image_data = NULL;
    size_t image_size;
    bool ok = false;
    pixman_image_t *pix = NULL;
    pixman_format_code_t format;
    int width, height, stride;

    if (fseek(fp, 0, SEEK_END) < 0) {
        LOG_ERRNO("%s: failed to seek to end of file", path);
        return NULL;
    }
    image_size = ftell(fp);
    if (fseek(fp, 0, SEEK_SET) < 0) {
        LOG_ERRNO("%s: failed to seek to beginning of file", path);
        return NULL;
    }

    if (!(file_data = WebPMalloc(image_size + 1))) {
        goto out;
    }

    clearerr(fp);
    if (fread(file_data, image_size, 1, fp) != image_size && ferror(fp)) {
        LOG_ERRNO("%s: failed to read", path);
        goto out;
    }
    file_data[image_size] = '\0';

    /* Verify it is a webp image */
    if (!WebPGetInfo(file_data, image_size, NULL, NULL)) {
        LOG_ERR("%s: not a WebP file", path);
        goto out;
    }

    image_data = WebPDecodeRGBA(file_data, image_size, &width, &height);
    if (image_data == NULL) {
        goto out;
    }
    format = PIXMAN_x8b8g8r8;
    stride = stride_for_format_and_width(format, width);

    ok = NULL != (pix = pixman_image_create_bits_no_clear(
        format, width, height, (uint32_t *)image_data, stride));

    if (!ok) {
        LOG_ERR("%s: failed to instantiate pixman image", path);
        goto out;
    }

out:
    WebPFree(file_data);
    if (!ok)
        WebPFree(image_data);

    return pix;
}
