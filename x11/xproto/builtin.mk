# $NetBSD: builtin.mk,v 1.4.52.1 2015/05/13 18:38:41 tron Exp $

BUILTIN_PKG:=	xproto
PKGCONFIG_FILE.xproto=	${X11BASE}/lib/pkgconfig/xproto.pc
PKGCONFIG_FILE.xproto+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
