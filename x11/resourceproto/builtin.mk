# $NetBSD: builtin.mk,v 1.1.2.1 2008/09/17 17:35:11 cube Exp $

BUILTIN_PKG:=	resourceproto
PKGCONFIG_FILE.resourceproto=	${X11BASE}/lib/pkgconfig/resourceproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
