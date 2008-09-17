# $NetBSD: builtin.mk,v 1.1.2.1 2008/09/17 17:29:50 cube Exp $

BUILTIN_PKG:=	scrnsaverproto
PKGCONFIG_FILE.scrnsaverproto=	${X11BASE}/lib/pkgconfig/scrnsaverproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
