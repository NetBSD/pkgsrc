# $NetBSD: builtin.mk,v 1.6 2019/11/03 09:14:11 rillig Exp $

BUILTIN_PKG:=			libXext
PKGCONFIG_FILE.libXext=		${X11BASE}/lib/pkgconfig/xext.pc
PKGCONFIG_FILE.libXext+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xext.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
