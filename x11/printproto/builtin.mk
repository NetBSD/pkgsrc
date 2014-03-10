# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:53 jperkin Exp $

BUILTIN_PKG:=	printproto
PKGCONFIG_FILE.printproto=	${X11BASE}/lib/pkgconfig/printproto.pc
PKGCONFIG_FILE.printproto+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/printproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
