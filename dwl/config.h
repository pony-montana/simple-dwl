#include <X11/XF86keysym.h>

/* constants */
#define TERMINAL "foot"
#define BROWSER "firefox-bin"

/* appearance */
static const int sloppyfocus               = 1;  /* focus follows mouse */
static const int bypass_surface_visibility = 0;  /* 1 means idle inhibitors will disable idle tracking even if it's surface isn't visible  */
static const unsigned int borderpx         = 1;  /* border pixel of windows */
static const float bordercolor[]           = {0.5, 0.5, 0.5, 1.0};
static const float focuscolor[]            = {1.0, 0.0, 0.0, 1.0};
/* To conform the xdg-protocol, set the alpha to zero to restore the old behavior */
static const float fullscreen_bg[]         = {0.1, 0.1, 0.1, 1.0};

/* Autostart */
static const char *const autostart[] = {
        "gentoo-pipewire-launcher", NULL,
	"dwl-bar", "&<-", NULL,
	"someblocks", "-s", "/tmp/1000-runtime-dir/dwl-bar-0", NULL,
	"swaybg", "-i", "/home/fu/.local/share/bg/babel.jpg", NULL,
        NULL /* terminate */
};

/* tagging - tagcount must be no greater than 31 */
static const int tagcount = 9;

static const Rule rules[] = {
	/* app_id     title       tags mask     isfloating  isterm  noswallow  monitor */
	/* examples:
	{ "Gimp",       NULL,       0,            1,          0,      1,         -1 },
	{ "firefox",    NULL,       1 << 8,       0,          0,      1,         -1 },
	*/
	{ TERMINAL,     NULL,       0,            0,          1,      1,         -1 },
};

/* layout(s) */
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* monitors */
static const MonitorRule monrules[] = {
	/* name       mfact nmaster scale layout       rotate/reflect                x    y */
	/* example of a HiDPI laptop monitor:
	{ "eDP-1",    0.5,  1,      2,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL,   -1,  -1 },
	*/
	/* defaults */
	{ NULL,       0.55, 1,      1,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL,   -1,  -1 },
};

/* keyboard */
static const struct xkb_rule_names xkb_rules = {
	/* can specify fields: rules, model, layout, variant, options */
	.layout  = "gb",
	.options = "caps:super",
};

static const int repeat_rate = 35;
static const int repeat_delay = 250;

/* Trackpad */
static const int tap_to_click = 1;
static const int tap_and_drag = 1;
static const int drag_lock = 1;
static const int natural_scrolling = 0;
static const int disable_while_typing = 1;
static const int left_handed = 0;
static const int middle_button_emulation = 0;
/* You can choose between:
LIBINPUT_CONFIG_SCROLL_NO_SCROLL
LIBINPUT_CONFIG_SCROLL_2FG
LIBINPUT_CONFIG_SCROLL_EDGE
LIBINPUT_CONFIG_SCROLL_ON_BUTTON_DOWN
*/
static const enum libinput_config_scroll_method scroll_method = LIBINPUT_CONFIG_SCROLL_2FG;

/* You can choose between:
LIBINPUT_CONFIG_CLICK_METHOD_NONE
LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS
LIBINPUT_CONFIG_CLICK_METHOD_CLICKFINGER
*/
static const enum libinput_config_click_method click_method = LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS;

/* You can choose between:
LIBINPUT_CONFIG_SEND_EVENTS_ENABLED
LIBINPUT_CONFIG_SEND_EVENTS_DISABLED
LIBINPUT_CONFIG_SEND_EVENTS_DISABLED_ON_EXTERNAL_MOUSE
*/
static const uint32_t send_events_mode = LIBINPUT_CONFIG_SEND_EVENTS_ENABLED;

/* You can choose between:
LIBINPUT_CONFIG_ACCEL_PROFILE_FLAT
LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE
*/
static const enum libinput_config_accel_profile accel_profile = LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE;
static const double accel_speed = 0.0;
/* You can choose between:
LIBINPUT_CONFIG_TAP_MAP_LRM -- 1/2/3 finger tap maps to left/right/middle
LIBINPUT_CONFIG_TAP_MAP_LMR -- 1/2/3 finger tap maps to left/middle/right
*/
static const enum libinput_config_tap_button_map button_map = LIBINPUT_CONFIG_TAP_MAP_LRM;

/* If you want to use the windows key for MODKEY, use WLR_MODIFIER_LOGO */
#define MODKEY WLR_MODIFIER_LOGO

#define TAGKEYS(KEY,SKEY,TAG) \
	{ MODKEY,                    KEY,            view,            {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_CTRL,  KEY,            toggleview,      {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_SHIFT, SKEY,           tag,             {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_CTRL|WLR_MODIFIER_SHIFT,SKEY,toggletag, {.ui = 1 << TAG} }

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[] = { "foot", NULL };
static const char *menucmd[] = { "bemenu-run", NULL };

static const Key keys[] = {
	/* Note that Shift changes certain key codes: c -> C, 2 -> at, etc. */
	/* modifier                  key                 function        argument */
        { 0,                         XF86XK_AudioRaiseVolume,	         spawn,		SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 0%- && wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%+ --limit 1.4") },
	{ 0,                         XF86XK_AudioLowerVolume,	         spawn,		SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 0%+ && wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%-") },
	{ MODKEY,                    XF86XK_AudioRaiseVolume,	         spawn,		SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 0%- && wpctl set-volume @DEFAULT_AUDIO_SINK@ 15%+ --limit 1.4") },
	{ MODKEY,                    XF86XK_AudioLowerVolume,	         spawn,		SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 0%+ && wpctl set-volume @DEFAULT_AUDIO_SINK@ 15%-") },
	{ MODKEY,                    XKB_KEY_d,          spawn,            {.v = menucmd} },
	{ MODKEY,                    XKB_KEY_Return,     spawn,            {.v = termcmd} },
        { MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_L,		 spawn,          SHCMD("swaylock --ignore-empty-password --show-failed-attempts --color 1e1e1e") },
        { MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_O,		 spawn,          SHCMD("wlr-randr --output LVDS-1 --off") },
        { MODKEY,                    XKB_KEY_o,		 spawn,          SHCMD("wlr-randr --output LVDS-1 --on") },
        { MODKEY,                    XKB_KEY_s,          spawn,          SHCMD("grim") },
	{ MODKEY,	             XKB_KEY_w,		 spawn,		   {.v = (const char*[]){ BROWSER, NULL } } },
	{ MODKEY,                    XKB_KEY_k,          focusstack,       {.i = +1} },
	{ MODKEY,                    XKB_KEY_j,          focusstack,       {.i = -1} },
	{ MODKEY,                    XKB_KEY_h,          setmfact,         {.f = -0.05} },
	{ MODKEY,                    XKB_KEY_l,          setmfact,         {.f = +0.05} },
	{ MODKEY,                    XKB_KEY_q,          killclient,       {0} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_T,          spawn,          SHCMD(TERMINAL " -e tremc") },
	{ MODKEY,                    XKB_KEY_t,          spawn,          SHCMD(TERMINAL " -e htop") },
	{ MODKEY,                    XKB_KEY_m,          spawn,          SHCMD(TERMINAL " -e neomutt") },
	{ MODKEY,                    XKB_KEY_r,          spawn,          SHCMD(TERMINAL " -e ranger") },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_Return,     zoom,             {0} },
        { MODKEY,                    XKB_KEY_f,          togglefullscreen, {0} },
        { MODKEY,                    XKB_KEY_space,      spawn,            {.v = termcmd} },
	TAGKEYS(          XKB_KEY_1, XKB_KEY_exclam,                       0),
	TAGKEYS(          XKB_KEY_2, XKB_KEY_quotedbl,                     1),
	TAGKEYS(          XKB_KEY_3, XKB_KEY_sterling,                     2),
	TAGKEYS(          XKB_KEY_4, XKB_KEY_dollar,                       3),
	TAGKEYS(          XKB_KEY_5, XKB_KEY_percent,                      4),
	TAGKEYS(          XKB_KEY_6, XKB_KEY_asciicircum,                  5),
	TAGKEYS(          XKB_KEY_7, XKB_KEY_ampersand,                    6),
	TAGKEYS(          XKB_KEY_8, XKB_KEY_asterisk,                     7),
	TAGKEYS(          XKB_KEY_9, XKB_KEY_parenleft,                    8),
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_Q,          quit,             {0} },

	/* Ctrl-Alt-Backspace and Ctrl-Alt-Fx used to be handled by X server */
	{ WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT,XKB_KEY_Terminate_Server, quit, {0} },
#define CHVT(n) { WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT,XKB_KEY_XF86Switch_VT_##n, chvt, {.ui = (n)} }
	CHVT(1), CHVT(2), CHVT(3), CHVT(4), CHVT(5), CHVT(6),
	CHVT(7), CHVT(8), CHVT(9), CHVT(10), CHVT(11), CHVT(12),
};

static const Button buttons[] = {
	{ MODKEY, BTN_LEFT,   moveresize,     {.ui = CurMove} },
	{ MODKEY, BTN_MIDDLE, togglefloating, {0} },
	{ MODKEY, BTN_RIGHT,  moveresize,     {.ui = CurResize} },
};

