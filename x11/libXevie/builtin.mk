# $NetBSD: builtin.mk,v 1.1.2.1 2008/09/18 03:09:52 cube Exp $

BUILTIN_PKG:=	libXevie
PKGCONFIG_FILE.libXevie=	${X11BASE}/lib/pkgconfig/xevie.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
