# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:51 jperkin Exp $

BUILTIN_PKG:=	damageproto
PKGCONFIG_FILE.damageproto=	${X11BASE}/lib/pkgconfig/damageproto.pc
PKGCONFIG_FILE.damageproto+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/damageproto.pc
PKGCONFIG_FILE.damageproto+=	${X11BASE}/share/pkgconfig/damageproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
