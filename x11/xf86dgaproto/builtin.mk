# $NetBSD: builtin.mk,v 1.1.2.2 2008/09/26 21:15:20 cube Exp $

BUILTIN_PKG:=	xf86dgaproto
PKGCONFIG_FILE.xf86dgaproto=	${X11BASE}/lib/pkgconfig/xf86dgaproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
