# $NetBSD: builtin.mk,v 1.1.2.1 2008/09/17 20:46:48 cube Exp $

BUILTIN_PKG:=	libFS
PKGCONFIG_FILE.libFS=	${X11BASE}/lib/pkgconfig/libfs.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
