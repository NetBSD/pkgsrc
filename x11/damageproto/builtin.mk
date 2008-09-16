# $NetBSD: builtin.mk,v 1.1.2.1 2008/09/16 03:04:48 cube Exp $

BUILTIN_PKG:=	damageproto
PKGCONFIG_FILE.damageproto=	${X11BASE}/lib/pkgconfig/damageproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
