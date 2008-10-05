# $NetBSD: builtin.mk,v 1.2 2008/10/05 21:36:34 cube Exp $

BUILTIN_PKG:=	videoproto
PKGCONFIG_FILE.videoproto=	${X11BASE}/lib/pkgconfig/videoproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
