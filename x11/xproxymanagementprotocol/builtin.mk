# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:54 jperkin Exp $

BUILTIN_PKG:=	xproxymanagementprotocol
PKGCONFIG_FILE.xproxymanagementprotocol=	${X11BASE}/lib/pkgconfig/xproxymngproto.pc
PKGCONFIG_FILE.xproxymanagementprotocol+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xproxymngproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
