# $NetBSD: builtin.mk,v 1.4 2019/11/03 09:14:12 rillig Exp $

BUILTIN_PKG:=			libXres
PKGCONFIG_FILE.libXres=		${X11BASE}/lib/pkgconfig/xres.pc
PKGCONFIG_FILE.libXres+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xres.pc
PKGCONFIG_FILE.libXres+=	${X11BASE}/lib/libXRes.so

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
