# $NetBSD: builtin.mk,v 1.4 2008/10/06 18:59:33 tron Exp $

BUILTIN_PKG:=	libXext
PKGCONFIG_FILE.libXext=	${X11BASE}/lib/pkgconfig/xext.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
