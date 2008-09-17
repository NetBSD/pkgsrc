# $NetBSD: builtin.mk,v 1.1.2.1 2008/09/17 18:29:27 cube Exp $

BUILTIN_PKG:=	evieext
PKGCONFIG_FILE.evieext=	${X11BASE}/lib/pkgconfig/evieproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
