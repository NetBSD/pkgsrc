# $NetBSD: builtin.mk,v 1.1.2.2 2008/09/26 21:15:18 cube Exp $

BUILTIN_PKG:=	damageproto
PKGCONFIG_FILE.damageproto=	${X11BASE}/lib/pkgconfig/damageproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
