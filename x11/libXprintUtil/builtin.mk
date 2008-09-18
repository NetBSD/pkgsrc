# $NetBSD: builtin.mk,v 1.1.2.1 2008/09/18 17:33:27 cube Exp $

BUILTIN_PKG:=	libXprintUtil
PKGCONFIG_FILE.libXprintUtil=	${X11BASE}/lib/pkgconfig/xprintutil.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
