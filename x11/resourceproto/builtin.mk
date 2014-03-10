# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:53 jperkin Exp $

BUILTIN_PKG:=	resourceproto
PKGCONFIG_FILE.resourceproto=	${X11BASE}/lib/pkgconfig/resourceproto.pc
PKGCONFIG_FILE.resourceproto+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/resourceproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
