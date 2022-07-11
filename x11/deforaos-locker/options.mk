# $NetBSD: options.mk,v 1.2 2022/07/11 01:36:50 khorben Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.deforaos-locker
PKG_SUPPORTED_OPTIONS=	embedded

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Membedded)
DEFORAOS_CONFIGURE_MODE=	embedded-debug
.endif
