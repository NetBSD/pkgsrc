# $NetBSD: builtin.mk,v 1.1.10.3 2008/09/26 21:15:19 cube Exp $

BUILTIN_PKG:=	libXinerama
PKGCONFIG_FILE.libXinerama=	${X11BASE}/lib/pkgconfig/xinerama.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
