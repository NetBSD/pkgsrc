# $NetBSD: builtin.mk,v 1.6 2018/03/07 11:57:37 wiz Exp $

BUILTIN_PKG:=	libXrandr
PKGCONFIG_FILE.libXrandr=	${X11BASE}/lib/pkgconfig/xrandr.pc
PKGCONFIG_FILE.libXrandr+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xrandr.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
