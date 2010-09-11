# $NetBSD: builtin.mk,v 1.1 2010/09/11 20:24:00 wiz Exp $

BUILTIN_PKG:=	xcb-util
PKGCONFIG_FILE.xcb-util=	${X11BASE}/lib/pkgconfig/xcb-atom.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
