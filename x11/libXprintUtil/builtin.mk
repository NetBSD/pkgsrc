# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:52 jperkin Exp $

BUILTIN_PKG:=	libXprintUtil
PKGCONFIG_FILE.libXprintUtil=	${X11BASE}/lib/pkgconfig/xprintutil.pc
PKGCONFIG_FILE.libXprintUtil+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xprintutil.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
