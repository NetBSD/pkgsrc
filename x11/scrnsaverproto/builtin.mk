# $NetBSD: builtin.mk,v 1.2 2008/10/05 21:36:34 cube Exp $

BUILTIN_PKG:=	scrnsaverproto
PKGCONFIG_FILE.scrnsaverproto=	${X11BASE}/lib/pkgconfig/scrnsaverproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
