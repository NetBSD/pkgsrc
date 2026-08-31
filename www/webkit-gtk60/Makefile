# $NetBSD: Makefile,v 1.2 2026/08/31 09:44:25 wiz Exp $

PLIST_SRC=	PLIST

.include "../../www/webkit-gtk41/Makefile.common"

PKGNAME=	${DISTNAME:S/webkitgtk/webkit-gtk60/}
PKGREVISION=	1
COMMENT=	GTK4 port of the WebKit browser engine (API 6.0)

# this enables the 6.0 API
CMAKE_CONFIGURE_ARGS+=		-DUSE_GTK4=ON

# Needed for JavaScript JIT
NOT_PAX_MPROTECT_SAFE+=		libexec/webkitgtk-6.0/MiniBrowser
NOT_PAX_MPROTECT_SAFE+=		libexec/webkitgtk-6.0/WebKitWebProcess
#NOT_PAX_MPROTECT_SAFE+=	libexec/webkitgtk-6.0/WebKitNetworkProcess
NOT_PAX_MPROTECT_SAFE+=		libexec/webkitgtk-6.0/jsc

.include "../../x11/gtk4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
