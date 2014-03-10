# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:53 jperkin Exp $

BUILTIN_PKG:=	scrnsaverproto
PKGCONFIG_FILE.scrnsaverproto=	${X11BASE}/lib/pkgconfig/scrnsaverproto.pc
PKGCONFIG_FILE.scrnsaverproto+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/scrnsaverproto.pc
PKGCONFIG_FILE.scrnsaverproto+=	${X11BASE}/share/pkgconfig/scrnsaverproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
