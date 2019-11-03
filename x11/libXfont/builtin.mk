# $NetBSD: builtin.mk,v 1.4 2019/11/03 09:14:11 rillig Exp $

BUILTIN_PKG:=			libXfont
PKGCONFIG_FILE.libXfont=	${X11BASE}/lib/pkgconfig/xfont.pc
PKGCONFIG_FILE.libXfont+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xfont.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
