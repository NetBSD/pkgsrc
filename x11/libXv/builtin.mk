# $NetBSD: builtin.mk,v 1.3 2019/11/03 09:14:12 rillig Exp $

BUILTIN_PKG:=		libXv
PKGCONFIG_FILE.libXv=	${X11BASE}/lib/pkgconfig/xv.pc
PKGCONFIG_FILE.libXv+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xv.pc
PKGCONFIG_FILE.libXv+=	${X11BASE}/lib/libXv.so

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
