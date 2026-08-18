# $NetBSD: builtin.mk,v 1.5 2026/08/18 07:39:40 wiz Exp $

BUILTIN_PKG:=		libXmu
PKGCONFIG_FILE.libXmu=	${X11BASE}/lib/pkgconfig/xmu.pc
PKGCONFIG_FILE.libXmu+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xinerama.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
