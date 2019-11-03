# $NetBSD: builtin.mk,v 1.2 2019/11/03 09:14:11 rillig Exp $

BUILTIN_PKG:=			libXfont2
PKGCONFIG_FILE.libXfont2=	${X11BASE}/lib/pkgconfig/xfont2.pc
PKGCONFIG_FILE.libXfont2+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xfont2.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
