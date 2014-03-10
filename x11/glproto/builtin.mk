# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:51 jperkin Exp $

BUILTIN_PKG:=	glproto
PKGCONFIG_FILE.glproto=		${X11BASE}/lib/pkgconfig/glproto.pc
PKGCONFIG_FILE.glproto+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/glproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
