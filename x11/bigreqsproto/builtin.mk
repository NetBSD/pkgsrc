# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:51 jperkin Exp $

BUILTIN_PKG:=	bigreqsproto
PKGCONFIG_FILE.bigreqsproto=	${X11BASE}/lib/pkgconfig/bigreqsproto.pc
PKGCONFIG_FILE.bigreqsproto+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/bigreqsproto.pc
PKGCONFIG_FILE.bigreqsproto+=	${X11BASE}/share/pkgconfig/bigreqsproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
