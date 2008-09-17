# $NetBSD: builtin.mk,v 1.1.2.1 2008/09/17 15:13:01 cube Exp $

BUILTIN_PKG:=	fontsproto
PKGCONFIG_FILE.fontsproto=	${X11BASE}/lib/pkgconfig/fontsproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
