# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:52 jperkin Exp $

BUILTIN_PKG:=	libXTrap
PKGCONFIG_FILE.libXTrap=	${X11BASE}/lib/pkgconfig/xtrap.pc
PKGCONFIG_FILE.libXTrap+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xtrap.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
