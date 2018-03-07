# $NetBSD: builtin.mk,v 1.2 2018/03/07 11:57:37 wiz Exp $

BUILTIN_PKG:=	libXpresent
PKGCONFIG_FILE.libXpresent=	${X11BASE}/lib/pkgconfig/xpresent.pc
PKGCONFIG_FILE.libXpresent+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xpresent.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
