# simple-dwl
wayland dwm clone; this is just my simple setup/clone.
Programs included:
- my setup/clone of dwl.
- my setup/clone of dwl-bar, a clone of the dwm default bar.
- my setup/clone of someblocks, a clone of dwmblocks. Just two simple and ugly blocks to put on the bar, just to show how it works.


!!! I putted the original readme in the respective folder. Note that the informations from it could be ambiguos. For example, dwl-bar readme says that if you want the ipc-protocol working you need to apply a patch. FALSE! These patch are just applied in the code. In general, the code here is ready to be compiled with my modifications. If reading readmes you feel you want to dive more into these programs, please go to the respective upstreams. In the end, do what you want but I'm not responsible for nothing here, I'm just sharing free code.


Features:
- full ipc-protocol-v2 support (in dwl and in dwl-bar), so you can click on the bar with your mouse and move across your desktops.
- support enabled for xwayland.
- swallow (hiding terminals under their child windows) and other things that makes the wm usable for me.
- clipboard unified across programs, in particular the function in the .zshrc that makes the "copy-pasting in the terminals" to use wl-clipboard.
- some choices are specific for my machine: a thinkpad x200 with uk keyboard running gentoo and (obviously) wayland.
- a beautiful wallpaper, the Tower of Babel of Pieter Bruegel. I picked it from www.wikipedia.org.

To complete your setup, you probably will need some programs from https://github.com/natpen/awesome-wayland.

I happily use:
- foot (wayland terminal)
- zsh (shell)
- imv (image viewer)
- zathura (pdf viewer)
- swaybg (wallpaper selector)
- swaylock (to lock your pc when you are away)
- wl-clipboard (simple clipboard for wayland)
- other common stuffs.
