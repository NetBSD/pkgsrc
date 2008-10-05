# $NetBSD: builtin.mk,v 1.4 2008/10/05 21:36:34 cube Exp $

BUILTIN_PKG:=	pixman
PKGCONFIG_FILE.pixman=	${X11BASE}/lib/pkgconfig/pixman-1.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
