# $NetBSD: builtin.mk,v 1.1.2.2 2008/09/26 21:15:19 cube Exp $

BUILTIN_PKG:=	pixman
PKGCONFIG_FILE.pixman=	${X11BASE}/lib/pkgconfig/pixman-1.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
