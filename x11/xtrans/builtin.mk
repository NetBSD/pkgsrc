# $NetBSD: builtin.mk,v 1.5 2019/11/03 09:14:21 rillig Exp $

BUILTIN_PKG:=		xtrans
PKGCONFIG_FILE.xtrans=	${X11BASE}/lib/pkgconfig/xtrans.pc
PKGCONFIG_FILE.xtrans+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xtrans.pc
PKGCONFIG_FILE.xtrans+=	${X11BASE}/share/pkgconfig/xtrans.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
