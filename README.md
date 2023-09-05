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

The original tower of babel everyone is searching that I stole from the museum of Wi Kipedia is in .local/share/bg

You can now clone this repo and copy the dotfiles in the right places.

# ATTENTION

!!! I putted the original readme in the respective folder so you can read all the informations you need to build programs.

Note that the informations from programs README are ambiguos. For example, dwl-bar readme says that if you want the ipc-protocol working you need to apply a patch. FALSE! These patch are already been applied in the code. In general, the code here is ready to be compiled with my modifications.

If reading readmes you feel you want to dive more into these programs, please go to the respective upstreams. In the end, do what you want but I'm not responsible for nothing here, I'm just sharing free code.

# Features

- full ipc-protocol-v2 support (in dwl and in dwl-bar), so you can click on the bar with your mouse and move across your desktops.
- support enabled for xwayland.
- swallow (hiding terminals under their child windows) and other things that makes the wm usable for me.
- clipboard unified across programs, in particular the function in the .zshrc that makes the "copy-pasting in the terminals" to use wl-clipboard.
- some choices are specific for my machine: a thinkpad x200 with uk keyboard running gentoo and (obviously) wayland.
- a beautiful wallpaper, the Tower of Babel of Pieter Bruegel. I picked it from www.wikipedia.org.

To complete your setup, you probably will need some programs from https://github.com/natpen/awesome-wayland.

#PROGRAM LIST

I use also:
- foot (wayland terminal)
- zsh (shell)
- imv (image viewer)
- zathura (pdf viewer)
- wbg (wallpaper selector)
- swaylock (to lock your pc when you are away)
- wl-clipboard (simple clipboard for wayland)
- other stuffs.

You find a pseudo-complete list in .local/share/packagelist.txt
