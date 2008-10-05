# $NetBSD: builtin.mk,v 1.2 2008/10/05 21:36:33 cube Exp $

BUILTIN_PKG:=	libXfont
PKGCONFIG_FILE.libXfont=	${X11BASE}/lib/pkgconfig/xfont.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
