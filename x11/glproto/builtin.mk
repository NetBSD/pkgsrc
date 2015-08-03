# $NetBSD: builtin.mk,v 1.4 2015/08/03 09:53:01 jperkin Exp $

BUILTIN_PKG:=	glproto
PKGCONFIG_FILE.glproto=		${X11BASE}/lib/pkgconfig/glproto.pc
PKGCONFIG_FILE.glproto+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/glproto.pc
PKGCONFIG_FILE.glproto+=	${X11BASE}/share/pkgconfig/glproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
