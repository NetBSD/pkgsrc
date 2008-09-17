# $NetBSD: builtin.mk,v 1.1.2.1 2008/09/17 18:31:02 cube Exp $

BUILTIN_PKG:=	xf86bigfontproto
PKGCONFIG_FILE.xf86bigfontproto=	${X11BASE}/lib/pkgconfig/xf86bigfontproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
