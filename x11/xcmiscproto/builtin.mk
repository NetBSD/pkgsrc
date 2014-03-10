# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:54 jperkin Exp $

BUILTIN_PKG:=	xcmiscproto
PKGCONFIG_FILE.xcmiscproto=	${X11BASE}/lib/pkgconfig/xcmiscproto.pc
PKGCONFIG_FILE.xcmiscproto+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xcmiscproto.pc
PKGCONFIG_FILE.xcmiscproto+=	${X11BASE}/share/pkgconfig/xcmiscproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
