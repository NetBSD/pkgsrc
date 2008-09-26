# $NetBSD: builtin.mk,v 1.1.2.2 2008/09/26 21:15:19 cube Exp $

BUILTIN_PKG:=	xcmiscproto
PKGCONFIG_FILE.xcmiscproto=	${X11BASE}/lib/pkgconfig/xcmiscproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
