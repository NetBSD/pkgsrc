# $NetBSD: builtin.mk,v 1.2 2014/03/10 11:05:53 jperkin Exp $

BUILTIN_PKG:=	libXtst
PKGCONFIG_FILE.libXtst=		${X11BASE}/lib/pkgconfig/xtst.pc
PKGCONFIG_FILE.libXtst+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xtst.pc
PKGCONFIG_FILE.libXtst+=	${X11BASE}/lib/libXtst.so

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
