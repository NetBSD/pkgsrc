# $NetBSD: builtin.mk,v 1.1 2019/08/23 15:12:00 rjs Exp $

BUILTIN_PKG:=	libxshmfence
PKGCONFIG_FILE.libxshmfence=	${X11BASE}/lib/pkgconfig/xshmfence.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
