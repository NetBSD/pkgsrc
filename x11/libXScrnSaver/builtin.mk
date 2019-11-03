# $NetBSD: builtin.mk,v 1.4 2019/11/03 09:14:10 rillig Exp $

BUILTIN_PKG:=			libXScrnSaver
PKGCONFIG_FILE.libXScrnSaver=	${X11BASE}/lib/pkgconfig/xscrnsaver.pc
PKGCONFIG_FILE.libXScrnSaver+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xscrnsaver.pc
PKGCONFIG_FILE.libXScrnSaver+=	${X11BASE}/lib/libXss.so

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
