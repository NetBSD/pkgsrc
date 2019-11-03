# $NetBSD: builtin.mk,v 1.3 2019/11/03 09:14:12 rillig Exp $

BUILTIN_PKG:=			libXtst
PKGCONFIG_FILE.libXtst=		${X11BASE}/lib/pkgconfig/xtst.pc
PKGCONFIG_FILE.libXtst+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xtst.pc
PKGCONFIG_FILE.libXtst+=	${X11BASE}/lib/libXtst.so

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
