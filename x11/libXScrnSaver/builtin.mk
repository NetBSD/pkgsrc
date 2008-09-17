# $NetBSD: builtin.mk,v 1.1.2.1 2008/09/17 20:46:48 cube Exp $

BUILTIN_PKG:=	libXScrnSaver
PKGCONFIG_FILE.libXScrnSaver=	${X11BASE}/lib/pkgconfig/xscrnsaver.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
