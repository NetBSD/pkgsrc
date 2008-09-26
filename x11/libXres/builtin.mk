# $NetBSD: builtin.mk,v 1.1.2.2 2008/09/26 21:15:19 cube Exp $

BUILTIN_PKG:=	libXres
PKGCONFIG_FILE.libXres=	${X11BASE}/lib/pkgconfig/xres.pc \
			${X11BASE}/lib/libXres.so

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
