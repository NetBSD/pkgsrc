# $NetBSD: builtin.mk,v 1.1.2.1 2008/09/17 17:22:02 cube Exp $

BUILTIN_PKG:=	recordproto
PKGCONFIG_FILE.recordproto=	${X11BASE}/lib/pkgconfig/recordproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
