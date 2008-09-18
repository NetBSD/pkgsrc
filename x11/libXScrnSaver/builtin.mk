# $NetBSD: builtin.mk,v 1.1.2.2 2008/09/18 02:23:04 cube Exp $

BUILTIN_PKG:=	libXScrnSaver
PKGCONFIG_FILE.libXScrnSaver=	${X11BASE}/lib/pkgconfig/xscrnsaver.pc \
				${X11BASE}/lib/libXss.so

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
