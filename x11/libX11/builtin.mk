# $NetBSD: builtin.mk,v 1.7 2019/11/03 09:14:10 rillig Exp $

BUILTIN_PKG:=		libX11
PKGCONFIG_FILE.libX11=	${X11BASE}/lib/pkgconfig/x11.pc
PKGCONFIG_FILE.libX11+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/x11.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
