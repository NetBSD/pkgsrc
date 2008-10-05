# $NetBSD: builtin.mk,v 1.2 2008/10/05 21:36:32 cube Exp $

BUILTIN_PKG:=	evieext
PKGCONFIG_FILE.evieext=	${X11BASE}/lib/pkgconfig/evieproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
