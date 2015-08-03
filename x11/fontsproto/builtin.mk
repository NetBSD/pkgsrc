# $NetBSD: builtin.mk,v 1.4 2015/08/03 09:53:01 jperkin Exp $

BUILTIN_PKG:=	fontsproto
PKGCONFIG_FILE.fontsproto=	${X11BASE}/lib/pkgconfig/fontsproto.pc
PKGCONFIG_FILE.fontsproto+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/fontsproto.pc
PKGCONFIG_FILE.fontsproto+=	${X11BASE}/share/pkgconfig/fontsproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
