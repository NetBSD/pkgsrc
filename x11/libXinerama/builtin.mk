# $NetBSD: builtin.mk,v 1.4 2019/11/03 09:14:11 rillig Exp $

BUILTIN_PKG:=			libXinerama
PKGCONFIG_FILE.libXinerama=	${X11BASE}/lib/pkgconfig/xinerama.pc
PKGCONFIG_FILE.libXinerama+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xinerama.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
