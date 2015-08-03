# $NetBSD: builtin.mk,v 1.3 2015/08/03 09:53:01 jperkin Exp $

BUILTIN_PKG:=	dri2proto
PKGCONFIG_FILE.dri2proto=	${X11BASE}/lib/pkgconfig/dri2proto.pc
PKGCONFIG_FILE.dri2proto+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/dri2proto.pc
PKGCONFIG_FILE.dri2proto+=	${X11BASE}/share/pkgconfig/dri2proto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
