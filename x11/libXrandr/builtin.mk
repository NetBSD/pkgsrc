# $NetBSD: builtin.mk,v 1.7 2019/11/03 09:14:12 rillig Exp $

BUILTIN_PKG:=			libXrandr
PKGCONFIG_FILE.libXrandr=	${X11BASE}/lib/pkgconfig/xrandr.pc
PKGCONFIG_FILE.libXrandr+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xrandr.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
