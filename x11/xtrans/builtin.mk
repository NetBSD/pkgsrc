# $NetBSD: builtin.mk,v 1.3 2013/04/18 13:22:06 obache Exp $

BUILTIN_PKG:=	xtrans
PKGCONFIG_FILE.xtrans=	${X11BASE}/lib/pkgconfig/xtrans.pc
PKGCONFIG_FILE.xtrans+=	${X11BASE}/share/pkgconfig/xtrans.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
