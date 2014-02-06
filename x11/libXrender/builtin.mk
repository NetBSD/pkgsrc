# $NetBSD: builtin.mk,v 1.3 2014/02/06 05:51:54 obache Exp $

BUILTIN_PKG:=	libXrender
PKGCONFIG_FILE.libXrender=	${X11BASE}/lib/pkgconfig/xrender.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
