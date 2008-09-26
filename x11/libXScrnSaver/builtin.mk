# $NetBSD: builtin.mk,v 1.1.2.3 2008/09/26 21:15:18 cube Exp $

BUILTIN_PKG:=	libXScrnSaver
PKGCONFIG_FILE.libXScrnSaver=	${X11BASE}/lib/pkgconfig/xscrnsaver.pc \
				${X11BASE}/lib/libXss.so

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
