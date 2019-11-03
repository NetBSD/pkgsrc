# $NetBSD: builtin.mk,v 1.5 2019/11/03 09:14:07 rillig Exp $

BUILTIN_PKG:=			evieext
PKGCONFIG_FILE.evieext=		${X11BASE}/lib/pkgconfig/evieproto.pc
PKGCONFIG_FILE.evieext+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/evieproto.pc
PKGCONFIG_FILE.evieext+=	${X11BASE}/share/pkgconfig/evieproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
