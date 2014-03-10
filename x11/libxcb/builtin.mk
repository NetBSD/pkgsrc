# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:53 jperkin Exp $

BUILTIN_PKG:=	libxcb
PKGCONFIG_FILE.libxcb=	${X11BASE}/lib/pkgconfig/xcb.pc
PKGCONFIG_FILE.libxcb+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xcb.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
