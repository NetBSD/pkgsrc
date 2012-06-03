# $NetBSD: hacks.mk,v 1.2 2012/06/03 18:06:11 dholland Exp $

#
# Work around x11-links lossage with native X on NetBSD 5.
#
# x11-links rejects xf86vidmodeproto because it's too old according
# to the pkgsrc X xf86vidmodeproto bl3 file (which is at best dubious
# logic) and doesn't link it. Then the .pc file isn't available, so
# this package's configure script silently fails running pkg-config
# and sets XVIDTUNE_LIBS to empty. The build then fails at link time
# because no X libs at all have been requested. Fix it by feeding in
# the result of running the same pkg-config invocation outside
# pkgsrc. The fact that the native xf86vidmode is "too old" does not
# itself break the package.
#
.include "../../mk/bsd.prefs.mk"
.if ${MACHINE_PLATFORM:MNetBSD-5*} && ${X11_TYPE} == "native"
NEEDED_LIBS=		-Wl,-R${X11BASE}/lib -L${X11BASE}/lib
NEEDED_LIBS+=		-lXxf86vm -lXaw7 -lXmu -lXt -lSM -lICE -lX11
CONFIGURE_ENV+=		XVIDTUNE_LIBS=${NEEDED_LIBS:Q}
.endif
