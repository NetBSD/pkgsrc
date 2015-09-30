# $NetBSD: builtin.mk,v 1.1 2015/09/30 09:10:39 leot Exp $

BUILTIN_PKG:=	presentproto
PKGCONFIG_FILE.presentproto=	${X11BASE}/lib/pkgconfig/presentproto.pc
PKGCONFIG_FILE.presentproto+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/presentproto.pc
PKGCONFIG_FILE.presentproto+=	${X11BASE}/share/pkgconfig/presentproto.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
