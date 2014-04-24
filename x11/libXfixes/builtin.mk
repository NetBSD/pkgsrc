# $NetBSD: builtin.mk,v 1.1 2014/04/24 12:18:09 obache Exp $

BUILTIN_PKG:=	libXfixes
PKGCONFIG_FILE.libXfixes=	${X11BASE}/lib/pkgconfig/xfixes.pc
PKGCONFIG_FILE.libXfixes+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xfixes.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
