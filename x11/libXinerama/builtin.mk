# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:52 jperkin Exp $

BUILTIN_PKG:=	libXinerama
PKGCONFIG_FILE.libXinerama=	${X11BASE}/lib/pkgconfig/xinerama.pc
PKGCONFIG_FILE.libXinerama+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xinerama.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
