# $NetBSD: options.mk,v 1.3 2026/07/08 12:43:27 hauke Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.davical
PKG_SUPPORTED_OPTIONS=	doxygen

PLIST_VARS+=		doxygen

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoxygen)
TOOL_DEPENDS+=	doxygen>=1.8.20:../../devel/doxygen
PLIST.doxygen=	yes
.else
BUILD_TARGET=	nodocs
.endif
