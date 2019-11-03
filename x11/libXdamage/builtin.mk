# $NetBSD: builtin.mk,v 1.4 2019/11/03 09:14:10 rillig Exp $

BUILTIN_PKG:=			libXdamage
PKGCONFIG_FILE.libXdamage=	${X11BASE}/lib/pkgconfig/xdamage.pc
PKGCONFIG_FILE.libXdamage+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xdamage.pc
PKGCONFIG_FILE.libXdamage+=	${X11BASE}/lib/libXdamage.so

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
