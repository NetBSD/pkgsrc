#!/bin/sh
set -eu

: ${XDG_CURRENT_DESKTOP:=sway}
: ${XDG_RUNTIME_DIR:=/tmp/$(id -un)-runtime}
: ${QT_QPA_PLATFORM:=wayland;xcb}

export XDG_CURRENT_DESKTOP XDG_RUNTIME_DIR QT_QPA_PLATFORM

[ -d "${XDG_RUNTIME_DIR}" ] || mkdir -p -m 700 "${XDG_RUNTIME_DIR}"

exec /usr/pkg/bin/seatd-launch \
     /usr/pkg/bin/dbus-run-session \
     /usr/pkg/bin/sway "$@"
