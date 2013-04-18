# $NetBSD: builtin.mk,v 1.2 2013/04/18 13:22:06 obache Exp $

BUILTIN_PKG:=				xkeyboard-config
PKGCONFIG_FILE.xkeyboard-config=	${X11BASE}/lib/pkgconfig/xkeyboard-config.pc
PKGCONFIG_FILE.xkeyboard-config+=	${X11BASE}/share/pkgconfig/xkeyboard-config.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
