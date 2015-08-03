# $NetBSD: builtin.mk,v 1.6 2015/08/03 09:53:02 jperkin Exp $

BUILTIN_PKG:=	xproto
PKGCONFIG_FILE.xproto=	${X11BASE}/lib/pkgconfig/xproto.pc
PKGCONFIG_FILE.xproto+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xproto.pc
PKGCONFIG_FILE.xproto+=	${X11BASE}/share/pkgconfig/xproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
