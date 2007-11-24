# $NetBSD: options.mk,v 1.1 2007/11/24 16:18:16 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-libwww

PKG_SUPPORTED_OPTIONS=	libwww-aliases

.if ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS=	libwww-aliases
.endif

.include "../../mk/bsd.options.mk"

###
### Do we install aliases ?
###
.if !empty(PKG_OPTIONS:Mlibwww-aliases)
ALIASES=		yes
.else
ALIASES=		no
.endif
