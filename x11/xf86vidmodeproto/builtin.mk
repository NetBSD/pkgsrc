# $NetBSD: builtin.mk,v 1.4 2015/08/03 09:53:01 jperkin Exp $

BUILTIN_PKG:=	xf86vidmodeproto
PKGCONFIG_FILE.xf86vidmodeproto=	${X11BASE}/lib/pkgconfig/xf86vidmodeproto.pc
PKGCONFIG_FILE.xf86vidmodeproto+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xf86vidmodeproto.pc
PKGCONFIG_FILE.xf86vidmodeproto+=	${X11BASE}/share/pkgconfig/xf86vidmodeproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
