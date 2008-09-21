# $NetBSD: builtin.mk,v 1.1.2.1 2008/09/21 21:36:41 cube Exp $

BUILTIN_PKG:=	libXres
PKGCONFIG_FILE.libXres=	${X11BASE}/lib/pkgconfig/xres.pc \
			${X11BASE}/lib/libXres.so

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
