# $NetBSD: builtin.mk,v 1.2 2008/10/05 21:36:33 cube Exp $

BUILTIN_PKG:=	libFS
PKGCONFIG_FILE.libFS=	${X11BASE}/lib/pkgconfig/libfs.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
