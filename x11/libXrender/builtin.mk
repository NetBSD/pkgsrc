# $NetBSD: builtin.mk,v 1.4 2014/03/10 11:05:52 jperkin Exp $

BUILTIN_PKG:=	libXrender
PKGCONFIG_FILE.libXrender=	${X11BASE}/lib/pkgconfig/xrender.pc
PKGCONFIG_FILE.libXrender+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xrender.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
