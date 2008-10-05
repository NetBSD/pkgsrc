# $NetBSD: builtin.mk,v 1.2 2008/10/05 21:36:33 cube Exp $

BUILTIN_PKG:=	fontsproto
PKGCONFIG_FILE.fontsproto=	${X11BASE}/lib/pkgconfig/fontsproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
