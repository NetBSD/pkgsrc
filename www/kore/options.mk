# $NetBSD: options.mk,v 1.2 2021/03/12 21:25:53 fcambus Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kore
PKG_SUPPORTED_OPTIONS=	acme curl debug

.include "../../mk/bsd.options.mk"

# Compile in ACME support
.if !empty(PKG_OPTIONS:Macme)
.  include "../../www/curl/buildlink3.mk"
MAKE_FLAGS+=	ACME=1
USE_TOOLS+=	pkg-config
.endif

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
