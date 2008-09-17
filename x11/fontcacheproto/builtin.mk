# $NetBSD: builtin.mk,v 1.1.2.1 2008/09/17 14:37:15 cube Exp $

BUILTIN_PKG:=	fontcacheproto
PKGCONFIG_FILE.fontcacheproto=	${X11BASE}/lib/pkgconfig/fontcacheproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
