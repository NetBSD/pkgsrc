# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:51 jperkin Exp $

BUILTIN_PKG:=	fontsproto
PKGCONFIG_FILE.fontsproto=	${X11BASE}/lib/pkgconfig/fontsproto.pc
PKGCONFIG_FILE.fontsproto+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/fontsproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
