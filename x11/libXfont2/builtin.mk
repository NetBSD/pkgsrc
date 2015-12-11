# $NetBSD: builtin.mk,v 1.1 2015/12/11 14:04:23 wiz Exp $

BUILTIN_PKG:=	libXfont2
PKGCONFIG_FILE.libXfont2=	${X11BASE}/lib/pkgconfig/xfont2.pc
PKGCONFIG_FILE.libXfont2+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xfont2.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
