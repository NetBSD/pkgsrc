# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:52 jperkin Exp $

BUILTIN_PKG:=	libXevie
PKGCONFIG_FILE.libXevie=	${X11BASE}/lib/pkgconfig/xevie.pc
PKGCONFIG_FILE.libXevie+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xevie.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
