# $NetBSD: builtin.mk,v 1.5 2025/03/19 11:12:17 wiz Exp $

BUILTIN_PKG:=		libXt
PKGCONFIG_FILE.libXt=	${X11BASE}/lib/pkgconfig/xt.pc
PKGCONFIG_FILE.libXt+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xt.pc
PKGCONFIG_FILE.libXt+=	${X11BASE}/lib/libXt.so

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
