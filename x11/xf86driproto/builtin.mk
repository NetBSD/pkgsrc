# $NetBSD: builtin.mk,v 1.2 2008/10/05 21:36:34 cube Exp $

BUILTIN_PKG:=	xf86driproto
PKGCONFIG_FILE.xf86driproto=	${X11BASE}/lib/pkgconfig/xf86driproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
