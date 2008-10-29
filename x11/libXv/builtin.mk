# $NetBSD: builtin.mk,v 1.1 2008/10/29 21:14:01 cube Exp $

BUILTIN_PKG:=	libXv
PKGCONFIG_FILE.libXv=	${X11BASE}/lib/pkgconfig/xv.pc \
				${X11BASE}/lib/libXv.so

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
