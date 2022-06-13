# $NetBSD: options.mk,v 1.3 2022/06/13 07:11:33 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.deforaos-panel
PKG_SUPPORTED_OPTIONS=	embedded

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Membedded)
DEFORAOS_CONFIGURE_MODE=	embedded-debug
.endif
