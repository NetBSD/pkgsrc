# $NetBSD: builtin.mk,v 1.5 2019/11/03 09:14:12 rillig Exp $

BUILTIN_PKG:=			libXrender
PKGCONFIG_FILE.libXrender=	${X11BASE}/lib/pkgconfig/xrender.pc
PKGCONFIG_FILE.libXrender+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xrender.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
