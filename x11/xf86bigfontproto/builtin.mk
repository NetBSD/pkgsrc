# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:54 jperkin Exp $

BUILTIN_PKG:=	xf86bigfontproto
PKGCONFIG_FILE.xf86bigfontproto=	${X11BASE}/lib/pkgconfig/xf86bigfontproto.pc
PKGCONFIG_FILE.xf86bigfontproto+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xf86bigfontproto.pc
PKGCONFIG_FILE.xf86bigfontproto+=	${X11BASE}/share/pkgconfig/xf86bigfontproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
