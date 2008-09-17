# $NetBSD: builtin.mk,v 1.1.2.1 2008/09/17 18:31:02 cube Exp $

BUILTIN_PKG:=	xf86vidmodeproto
PKGCONFIG_FILE.xf86vidmodeproto=	${X11BASE}/lib/pkgconfig/xf86vidmodeproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
