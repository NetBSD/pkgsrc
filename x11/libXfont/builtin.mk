# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:52 jperkin Exp $

BUILTIN_PKG:=	libXfont
PKGCONFIG_FILE.libXfont=	${X11BASE}/lib/pkgconfig/xfont.pc
PKGCONFIG_FILE.libXfont+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xfont.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
