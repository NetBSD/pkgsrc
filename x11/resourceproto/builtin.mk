# $NetBSD: builtin.mk,v 1.2 2008/10/05 21:36:34 cube Exp $

BUILTIN_PKG:=	resourceproto
PKGCONFIG_FILE.resourceproto=	${X11BASE}/lib/pkgconfig/resourceproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
