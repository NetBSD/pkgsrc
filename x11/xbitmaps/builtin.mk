# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:53 jperkin Exp $

BUILTIN_PKG:=	xbitmaps
PKGCONFIG_FILE.xbitmaps=	${X11BASE}/lib/pkgconfig/xbitmaps.pc
PKGCONFIG_FILE.xbitmaps+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xbitmaps.pc
PKGCONFIG_FILE.xbitmaps+=	${X11BASE}/share/pkgconfig/xbitmaps.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
