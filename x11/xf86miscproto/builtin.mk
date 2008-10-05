# $NetBSD: builtin.mk,v 1.2 2008/10/05 21:36:34 cube Exp $

BUILTIN_PKG:=	xf86miscproto
PKGCONFIG_FILE.xf86miscproto=	${X11BASE}/lib/pkgconfig/xf86miscproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
