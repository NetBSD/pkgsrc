# $NetBSD: builtin.mk,v 1.1.2.1 2008/09/17 18:31:02 cube Exp $

BUILTIN_PKG:=	xproxymanagementprotocol
PKGCONFIG_FILE.xproxymanagementprotocol=	${X11BASE}/lib/pkgconfig/xproxymngproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
