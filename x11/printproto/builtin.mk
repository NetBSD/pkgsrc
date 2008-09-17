# $NetBSD: builtin.mk,v 1.1.2.1 2008/09/17 16:38:58 cube Exp $

BUILTIN_PKG:=	printproto
PKGCONFIG_FILE.printproto=	${X11BASE}/lib/pkgconfig/printproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
