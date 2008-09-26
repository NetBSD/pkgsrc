# $NetBSD: builtin.mk,v 1.1.2.2 2008/09/26 21:15:19 cube Exp $

BUILTIN_PKG:=	libXprintUtil
PKGCONFIG_FILE.libXprintUtil=	${X11BASE}/lib/pkgconfig/xprintutil.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
