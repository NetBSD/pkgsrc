# $NetBSD: builtin.mk,v 1.5 2014/03/10 11:05:52 jperkin Exp $

BUILTIN_PKG:=	libXext
PKGCONFIG_FILE.libXext=		${X11BASE}/lib/pkgconfig/xext.pc
PKGCONFIG_FILE.libXext+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xext.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
