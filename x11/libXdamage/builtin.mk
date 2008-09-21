# $NetBSD: builtin.mk,v 1.1.2.1 2008/09/21 17:04:13 cube Exp $

BUILTIN_PKG:=	libXdamage
PKGCONFIG_FILE.libXdamage=	${X11BASE}/lib/pkgconfig/xdamage.pc \
				${X11BASE}/lib/libXdamage.so

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
