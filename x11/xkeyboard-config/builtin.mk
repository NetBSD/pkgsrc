# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:54 jperkin Exp $

BUILTIN_PKG:=				xkeyboard-config
PKGCONFIG_FILE.xkeyboard-config=	${X11BASE}/lib/pkgconfig/xkeyboard-config.pc
PKGCONFIG_FILE.xkeyboard-config+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xkeyboard-config.pc
PKGCONFIG_FILE.xkeyboard-config+=	${X11BASE}/share/pkgconfig/xkeyboard-config.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
