# $NetBSD: builtin.mk,v 1.1 2010/09/11 19:46:59 tron Exp $

BUILTIN_PKG:=	xcb-proto
PKGCONFIG_FILE.xcb-proto=	${X11BASE}/lib/pkgconfig/xcb-proto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
