# $NetBSD: builtin.mk,v 1.1.2.1 2008/09/18 17:33:27 cube Exp $

BUILTIN_PKG:=	liblbxutil
PKGCONFIG_FILE.liblbxutil=	${X11BASE}/lib/pkgconfig/lbxutil.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
