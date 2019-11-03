# $NetBSD: builtin.mk,v 1.4 2019/11/03 09:14:11 rillig Exp $

BUILTIN_PKG:=			libXevie
PKGCONFIG_FILE.libXevie=	${X11BASE}/lib/pkgconfig/xevie.pc
PKGCONFIG_FILE.libXevie+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xevie.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
