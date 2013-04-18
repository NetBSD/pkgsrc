# $NetBSD: builtin.mk,v 1.2 2013/04/18 13:22:06 obache Exp $

BUILTIN_PKG:=	xcb-proto
PKGCONFIG_FILE.xcb-proto=	${X11BASE}/lib/pkgconfig/xcb-proto.pc
PKGCONFIG_FILE.xcb-proto+=	${X11BASE}/share/pkgconfig/xcb-proto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
