# $NetBSD: builtin.mk,v 1.1 2011/09/21 14:58:37 joerg Exp $

BUILTIN_PKG:=	xbitmaps
PKGCONFIG_FILE.xbitmaps=	${X11BASE}/lib/pkgconfig/xbitmaps.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
