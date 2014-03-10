# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:53 jperkin Exp $

BUILTIN_PKG:=	libXres
PKGCONFIG_FILE.libXres=		${X11BASE}/lib/pkgconfig/xres.pc
PKGCONFIG_FILE.libXres+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xres.pc
PKGCONFIG_FILE.libXres+=	${X11BASE}/lib/libXRes.so

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
