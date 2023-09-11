#!/bin/sh
if [ -f /usr/X11R7/lib/libEGL.so ] && [ -z "$LD_PRELOAD" ] && \
  nm /usr/X11R7/lib/libGL.so | grep -Fq "B _glapi_tls_Dispatch"; then
    # Temporary workaround for PR#57445
    # This may not avoid a crash 100% of the time, but changes at least some
    # cases of 100% crash on startup to "have not yet seen crash on startup"
    echo "Applying libEGL LD_PRELOAD workaround for NetBSD" >&2
    export LD_PRELOAD=/usr/X11R7/lib/libEGL.so
    # Note that there is an _additional_ issue with firefox >= 111 that
    # needs to be addressed, and that is worked around by disabling webgl
    # by default, but it's not even worth looking at that on a system without
    # the fixed libGL
fi
exec /usr/pkg/lib/firefox/firefox "$@"
