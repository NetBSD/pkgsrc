# $NetBSD: builtin.mk,v 1.4 2022/12/20 18:56:06 wiz Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILTIN_PKG:=	modular-xorg-server

PKGCONFIG_FILE.modular-xorg-server=	${X11BASE}/lib/pkgconfig/xorg-server.pc
PKGCONFIG_BASE.modular-xorg-server=	${X11BASE}

.include "../../mk/buildlink3/pkgconfig-builtin.mk"

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###

CHECK_BUILTIN.modular-xorg-server?=		no
.if ${CHECK_BUILTIN.modular-xorg-server:tl} == no

.  if ${USE_BUILTIN.modular-xorg-server:tl} == yes
BUILDLINK_PREFIX.modular-xorg-server=	${X11BASE}
BUILDLINK_FILES.modular-xorg-server+=	lib/pkgconfig/xorg-server.pc
.  endif

.endif  # CHECK_BUILTIN.modular-xorg-server
