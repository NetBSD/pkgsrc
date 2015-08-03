# $NetBSD: builtin.mk,v 1.4 2015/08/03 09:53:02 jperkin Exp $

BUILTIN_PKG:=	xproxymanagementprotocol
PKGCONFIG_FILE.xproxymanagementprotocol=	${X11BASE}/lib/pkgconfig/xproxymngproto.pc
PKGCONFIG_FILE.xproxymanagementprotocol+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xproxymngproto.pc
PKGCONFIG_FILE.xproxymanagementprotocol+=	${X11BASE}/share/pkgconfig/xproxymngproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
