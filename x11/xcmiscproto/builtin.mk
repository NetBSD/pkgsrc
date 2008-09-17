# $NetBSD: builtin.mk,v 1.1.2.1 2008/09/17 18:36:12 cube Exp $

BUILTIN_PKG:=	xcmiscproto
PKGCONFIG_FILE.xcmiscproto=	${X11BASE}/lib/pkgconfig/xcmiscproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
