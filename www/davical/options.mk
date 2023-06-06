# $NetBSD: options.mk,v 1.2 2023/06/06 12:42:38 riastradh Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.${PHP_PKG_PREFIX}-davical
PKG_SUPPORTED_OPTIONS=	doxygen

PLIST_VARS+=		doxygen

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoxygen)
TOOL_DEPENDS+=	doxygen>=1.8.20:../../devel/doxygen
PLIST.doxygen=		yes
.else
BUILD_TARGET=	nodocs
.endif
