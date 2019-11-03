# $NetBSD: builtin.mk,v 1.4 2019/11/03 09:14:19 rillig Exp $

BUILTIN_PKG:=			xcb-proto
PKGCONFIG_FILE.xcb-proto=	${X11BASE}/lib/pkgconfig/xcb-proto.pc
PKGCONFIG_FILE.xcb-proto+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xcb-proto.pc
PKGCONFIG_FILE.xcb-proto+=	${X11BASE}/share/pkgconfig/xcb-proto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
