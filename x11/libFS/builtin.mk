# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:52 jperkin Exp $

BUILTIN_PKG:=	libFS
PKGCONFIG_FILE.libFS=	${X11BASE}/lib/pkgconfig/libfs.pc
PKGCONFIG_FILE.libFS+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/libfs.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
