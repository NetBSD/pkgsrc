# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:53 jperkin Exp $

BUILTIN_PKG:=	recordproto
PKGCONFIG_FILE.recordproto=	${X11BASE}/lib/pkgconfig/recordproto.pc
PKGCONFIG_FILE.recordproto+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/recordproto.pc
PKGCONFIG_FILE.recordproto+=	${X11BASE}/share/pkgconfig/recordproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
