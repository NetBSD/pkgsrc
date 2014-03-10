# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:53 jperkin Exp $

BUILTIN_PKG:=	libdrm
PKGCONFIG_FILE.libdrm=	${X11BASE}/lib/pkgconfig/libdrm.pc
PKGCONFIG_FILE.libdrm+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/libdrm.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
