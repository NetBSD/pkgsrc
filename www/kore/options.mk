# $NetBSD: options.mk,v 1.1 2019/08/22 13:30:31 fcambus Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kore
PKG_SUPPORTED_OPTIONS=	curl debug

.include "../../mk/bsd.options.mk"

# Compile in asynchronous curl support
.if !empty(PKG_OPTIONS:Mcurl)
.  include "../../www/curl/buildlink3.mk"
MAKE_FLAGS+=	CURL=1
USE_TOOLS+=	pkg-config
.endif

# Enable use of -d for debug
.if !empty(PKG_OPTIONS:Mdebug)
MAKE_FLAGS+=	DEBUG=1
.endif
