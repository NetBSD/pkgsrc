# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:52 jperkin Exp $

BUILTIN_PKG:=	libXdamage
PKGCONFIG_FILE.libXdamage=	${X11BASE}/lib/pkgconfig/xdamage.pc
PKGCONFIG_FILE.libXdamage+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xdamage.pc
PKGCONFIG_FILE.libXdamage+=	${X11BASE}/lib/libXdamage.so

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
