# $NetBSD: Makefile,v 1.6 2026/09/29 06:08:10 wiz Exp $

PLIST_SRC=	PLIST

PKGREVISION= 2
.include "Makefile.common"

PKGNAME=	${DISTNAME:S/webkitgtk/webkit-gtk41/}
COMMENT=	GTK3 port of the WebKit browser engine (API 4.1)

CMAKE_CONFIGURE_ARGS+=		-DUSE_GTK4=OFF

# Needed for JavaScript JIT
#NOT_PAX_MPROTECT_SAFE+=	libexec/webkit2gtk-4.1/MiniBrowser
NOT_PAX_MPROTECT_SAFE+=		libexec/webkit2gtk-4.1/WebKitWebProcess
#NOT_PAX_MPROTECT_SAFE+=	libexec/webkit2gtk-4.1/WebKitNetworkProcess
NOT_PAX_MPROTECT_SAFE+=		libexec/webkit2gtk-4.1/jsc

.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
