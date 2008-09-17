# $NetBSD: builtin.mk,v 1.1.2.1 2008/09/17 04:28:12 cube Exp $

BUILTIN_PKG:=	bigreqsproto
PKGCONFIG_FILE.bigreqsproto=	${X11BASE}/lib/pkgconfig/bigreqsproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
