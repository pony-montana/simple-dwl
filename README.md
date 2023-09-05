# simple-dwl
wayland dwm clone; this is just my simple setup/fork.
Programs included:
- my setup/fork of dwl.
- my setup/fork of dwl-bar, a clone of the dwm default bar.
- my setup/fork of someblocks, a clone of dwmblocks. Just two simple and ugly blocks to put on the bar, just to show how it works.
- sources for building wbg and wlsunset, two utilities used respectively for background image and blue-light reduction.
- some dotfiles.

# REPOSITORY MAP

The programs you are here for are probably in .local/src/

You will find dotfiles in .config

A pseudo-complete list of program I use is in .local/share/packagelist.txt

The original tower of babel everyone is searching that I stole from the museum of Wi Kipedia is in .local/share/bg

# ATTENTION

!!! I putted the original readme in the respective folder so you can read all the informations you need to build programs.

Note that the informations from programs README are ambiguos. For example, dwl-bar readme says that if you want the ipc-protocol working you need to apply a patch. FALSE! These patch are already been applied in the code. In general, the code here is ready to be compiled with my modifications.

If reading readmes you feel you want to dive more into these programs, please go to the respective upstreams. In the end, do what you want but I'm not responsible for nothing here, I'm just sharing free code.

# Features

- full ipc-protocol-v2 support (in dwl and in dwl-bar), so you can click on the bar with your mouse and move across your desktops.
- support enabled for xwayland.
- swallow (hiding terminals under their child windows) and other things that makes the wm usable for me.
- clipboard unified across programs, in particular the function in the .zshrc that makes the "copy-pasting in the terminals" to use wl-clipboard.
- reproducing images in the terminal with ranger + foot + imagemagick(sixel).
- some choices are specific for my machine: a thinkpad x200 with uk keyboard running gentoo and (obviously) wayland. I don't use pipewire on this machine/setup, but just pure alsa.
- a beautiful wallpaper, the Tower of Babel of Pieter Bruegel. I picked it from www.wikipedia.org.


# PROGRAM LIST

You find the pseudo-complete list in .local/share/packagelist.txt

You can find some alternatives in https://github.com/natpen/awesome-wayland.

# DONATIONS 

![Bitcoin_accepted_here-1024x512-1883043927](https://github.com/pony-montana/simple-dwl/assets/96387969/a8604d5c-305a-4701-b6a1-1f4fb2d45a91)


Just in case someone appreciate my work, you can donate some sats (bitcoin) ("absolute digital scarcity", if you prefer) at:

![wallet](https://github.com/pony-montana/simple-dwl/assets/96387969/17d2399d-8f19-4ac8-8a3f-91b56c6d4199)

bc1qvvk2z8pp2sl3y5cmuy32dr7egnr9ktv5grlccz
