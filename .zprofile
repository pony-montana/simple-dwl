#!/bin/zsh

# profile file. Runs on login. Environmental variables are set here.

# If you don't plan on reverting to bash, you can remove the link in ~/.profile
# to clean up.

# Adds `~/.local/bin` to $PATH
export PATH="$PATH:${$(find ~/.local/bin -type d -printf %p:)%%:}"

unsetopt PROMPT_SP

if test -z "${XDG_RUNTIME_DIR}"; then
 export XDG_RUNTIME_DIR=/tmp/$(id -u)-runtime-dir
if ! test -d "${XDG_RUNTIME_DIR}"; then
 mkdir "${XDG_RUNTIME_DIR}"
 chmod 0700 "${XDG_RUNTIME_DIR}"
 fi
fi

export XDG_CURRENT_DESKTOP=dwl
export XDG_SESSION_DESKTOP=dwl
export EGL_PLATFORM=wayland
export QT_QPA_PLATFORM=wayland
export MOZ_ENABLE_WAYLAND=1

# Default programs:
export EDITOR="nvim"
export TERMINAL="foot"
export TERMINAL_PROG="foot"
export BROWSER="firefox-bin"

# ~/ Clean-up:
export XDG_CONFIG_HOME="$HOME/.config"
export XDG_DATA_HOME="$HOME/.local/share"
export XDG_CACHE_HOME="$HOME/.cache"
export NOTMUCH_CONFIG="$XDG_CONFIG_HOME/notmuch-config"
export INPUTRC="$XDG_CONFIG_HOME/shell/inputrc"
export ZDOTDIR="$XDG_CONFIG_HOME/zsh"
export PASSWORD_STORE_DIR="$XDG_DATA_HOME/password-store"
export ANDROID_SDK_HOME="$XDG_CONFIG_HOME/android"
export HISTFILE="$XDG_DATA_HOME/history"
export MBSYNCRC="$XDG_CONFIG_HOME/mbsync/config"


[ ! -f ${XDG_CONFIG_HOME:-$HOME/.config}/shell/shortcutrc ] && setsid shortcuts >/dev/null 2>&1

exec dbus-run-session dwl -s $HOME/.local/bin/dwlstartup
