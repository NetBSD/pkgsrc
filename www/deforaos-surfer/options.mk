# $NetBSD: options.mk,v 1.2 2022/11/15 18:27:53 khorben Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.deforaos-surfer
PKG_SUPPORTED_OPTIONS=	embedded

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Membedded)
DEFORAOS_CONFIGURE_MODE=	embedded-webkit-4-debug
.else
DEFORAOS_CONFIGURE_MODE=	webkit-4-debug
.endif
