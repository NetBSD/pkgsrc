# $NetBSD: builtin.mk,v 1.1.2.1 2008/09/17 16:29:52 cube Exp $

BUILTIN_PKG:=	glproto
PKGCONFIG_FILE.glproto=	${X11BASE}/lib/pkgconfig/glproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
