# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:53 jperkin Exp $

BUILTIN_PKG:=	trapproto
PKGCONFIG_FILE.trapproto=	${X11BASE}/lib/pkgconfig/trapproto.pc
PKGCONFIG_FILE.trapproto+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/trapproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
