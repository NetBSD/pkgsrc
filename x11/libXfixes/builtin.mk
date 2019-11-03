# $NetBSD: builtin.mk,v 1.2 2019/11/03 09:14:11 rillig Exp $

BUILTIN_PKG:=			libXfixes
PKGCONFIG_FILE.libXfixes=	${X11BASE}/lib/pkgconfig/xfixes.pc
PKGCONFIG_FILE.libXfixes+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xfixes.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
