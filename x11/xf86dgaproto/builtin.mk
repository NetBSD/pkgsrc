# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:54 jperkin Exp $

BUILTIN_PKG:=	xf86dgaproto
PKGCONFIG_FILE.xf86dgaproto=	${X11BASE}/lib/pkgconfig/xf86dgaproto.pc
PKGCONFIG_FILE.xf86dgaproto+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xf86dgaproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
