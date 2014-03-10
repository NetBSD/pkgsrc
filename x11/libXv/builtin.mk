# $NetBSD: builtin.mk,v 1.2 2014/03/10 11:05:53 jperkin Exp $

BUILTIN_PKG:=	libXv
PKGCONFIG_FILE.libXv=	${X11BASE}/lib/pkgconfig/xv.pc
PKGCONFIG_FILE.libXv+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xv.pc
PKGCONFIG_FILE.libXv+=	${X11BASE}/lib/libXv.so

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
