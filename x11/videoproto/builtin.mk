# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:53 jperkin Exp $

BUILTIN_PKG:=	videoproto
PKGCONFIG_FILE.videoproto=	${X11BASE}/lib/pkgconfig/videoproto.pc
PKGCONFIG_FILE.videoproto+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/videoproto.pc
PKGCONFIG_FILE.videoproto+=	${X11BASE}/share/pkgconfig/videoproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
