# $NetBSD: builtin.mk,v 1.2 2013/04/18 13:22:06 obache Exp $

BUILTIN_PKG:=	xbitmaps
PKGCONFIG_FILE.xbitmaps=	${X11BASE}/lib/pkgconfig/xbitmaps.pc
PKGCONFIG_FILE.xbitmaps+=	${X11BASE}/share/pkgconfig/xbitmaps.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
