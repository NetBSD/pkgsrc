# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:51 jperkin Exp $

BUILTIN_PKG:=	evieext
PKGCONFIG_FILE.evieext=		${X11BASE}/lib/pkgconfig/evieproto.pc
PKGCONFIG_FILE.evieext+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/evieproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
