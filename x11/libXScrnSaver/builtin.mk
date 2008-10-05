# $NetBSD: builtin.mk,v 1.2 2008/10/05 21:36:33 cube Exp $

BUILTIN_PKG:=	libXScrnSaver
PKGCONFIG_FILE.libXScrnSaver=	${X11BASE}/lib/pkgconfig/xscrnsaver.pc \
				${X11BASE}/lib/libXss.so

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
