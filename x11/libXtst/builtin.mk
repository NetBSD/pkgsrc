# $NetBSD: builtin.mk,v 1.1 2008/12/04 04:16:41 cube Exp $

BUILTIN_PKG:=	libXtst
PKGCONFIG_FILE.libXtst=	${X11BASE}/lib/pkgconfig/xtst.pc \
				${X11BASE}/lib/libXtst.so

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
