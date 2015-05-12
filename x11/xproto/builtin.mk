# $NetBSD: builtin.mk,v 1.5 2015/05/12 13:59:11 hiramatsu Exp $

BUILTIN_PKG:=	xproto
PKGCONFIG_FILE.xproto=	${X11BASE}/lib/pkgconfig/xproto.pc
PKGCONFIG_FILE.xproto+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
