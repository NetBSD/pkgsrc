# $NetBSD: builtin.mk,v 1.3 2019/11/03 09:14:12 rillig Exp $

BUILTIN_PKG:=			libXpresent
PKGCONFIG_FILE.libXpresent=	${X11BASE}/lib/pkgconfig/xpresent.pc
PKGCONFIG_FILE.libXpresent+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xpresent.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
