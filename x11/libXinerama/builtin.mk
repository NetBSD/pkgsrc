# $NetBSD: builtin.mk,v 1.1.10.2 2008/09/21 22:58:06 cube Exp $

BUILTIN_PKG:=	libXinerama
PKGCONFIG_FILE.libXinerama=	${X11BASE}/lib/pkgconfig/xinerama.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
