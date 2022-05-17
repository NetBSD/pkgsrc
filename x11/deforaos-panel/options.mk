# $NetBSD: options.mk,v 1.2 2022/05/17 18:01:28 khorben Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.deforaos-panel
PKG_SUPPORTED_OPTIONS=	embedded

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Membedded)
DEFORAOS_CONFIGURE_MODE=embedded-debug
.endif
