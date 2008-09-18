# $NetBSD: builtin.mk,v 1.1.2.1 2008/09/18 19:30:37 cube Exp $

BUILTIN_PKG:=	xtrans
PKGCONFIG_FILE.xtrans=	${X11BASE}/lib/pkgconfig/xtrans.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
