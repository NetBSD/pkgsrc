# $NetBSD: builtin.mk,v 1.4 2015/08/03 09:53:01 jperkin Exp $

BUILTIN_PKG:=	resourceproto
PKGCONFIG_FILE.resourceproto=	${X11BASE}/lib/pkgconfig/resourceproto.pc
PKGCONFIG_FILE.resourceproto+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/resourceproto.pc
PKGCONFIG_FILE.resourceproto+=	${X11BASE}/share/pkgconfig/resourceproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
