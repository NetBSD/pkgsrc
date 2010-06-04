# $NetBSD: builtin.mk,v 1.1 2010/06/04 10:49:01 ghen Exp $

BUILTIN_PKG:=				xkeyboard-config
PKGCONFIG_FILE.xkeyboard-config=	${X11BASE}/lib/pkgconfig/xkeyboard-config.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
