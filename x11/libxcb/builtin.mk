# $NetBSD: builtin.mk,v 1.4 2019/11/03 09:14:13 rillig Exp $

BUILTIN_PKG:=		libxcb
PKGCONFIG_FILE.libxcb=	${X11BASE}/lib/pkgconfig/xcb.pc
PKGCONFIG_FILE.libxcb+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xcb.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
