# $NetBSD: builtin.mk,v 1.1.2.1 2008/09/17 18:31:01 cube Exp $

BUILTIN_PKG:=	videoproto
PKGCONFIG_FILE.videoproto=	${X11BASE}/lib/pkgconfig/videoproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
