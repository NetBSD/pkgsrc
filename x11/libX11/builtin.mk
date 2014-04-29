# $NetBSD: builtin.mk,v 1.6 2014/04/29 07:45:42 obache Exp $

BUILTIN_PKG:=	libX11
PKGCONFIG_FILE.libX11=		${X11BASE}/lib/pkgconfig/x11.pc
PKGCONFIG_FILE.libX11+=		${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/x11.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
