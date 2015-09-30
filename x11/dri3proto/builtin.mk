# $NetBSD: builtin.mk,v 1.1 2015/09/30 09:08:43 leot Exp $

BUILTIN_PKG:=	dri3proto
PKGCONFIG_FILE.dri3proto=	${X11BASE}/lib/pkgconfig/dri3proto.pc
PKGCONFIG_FILE.dri3proto+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/dri3proto.pc
PKGCONFIG_FILE.dri3proto+=	${X11BASE}/share/pkgconfig/dri3proto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
