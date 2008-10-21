# $NetBSD: options.mk,v 1.2 2008/10/21 13:12:27 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-libwww

PKG_SUPPORTED_OPTIONS=	libwww-aliases

.include "../../mk/bsd.options.mk"

###
### Do we install aliases ?
###
.if !empty(PKG_OPTIONS:Mlibwww-aliases)
MAKE_PARAMS+=		--aliases
.endif
