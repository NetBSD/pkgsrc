# $NetBSD: builtin.mk,v 1.1.2.1 2008/09/18 02:40:26 cube Exp $

BUILTIN_PKG:=	libXTrap
PKGCONFIG_FILE.libXTrap=	${X11BASE}/lib/pkgconfig/xtrap.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
