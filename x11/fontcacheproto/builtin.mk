# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:51 jperkin Exp $

BUILTIN_PKG:=	fontcacheproto
PKGCONFIG_FILE.fontcacheproto=	${X11BASE}/lib/pkgconfig/fontcacheproto.pc
PKGCONFIG_FILE.fontcacheproto+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/fontcacheproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
