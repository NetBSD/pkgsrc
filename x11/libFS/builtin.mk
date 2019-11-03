# $NetBSD: builtin.mk,v 1.4 2019/11/03 09:14:10 rillig Exp $

BUILTIN_PKG:=		libFS
PKGCONFIG_FILE.libFS=	${X11BASE}/lib/pkgconfig/libfs.pc
PKGCONFIG_FILE.libFS+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/libfs.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
