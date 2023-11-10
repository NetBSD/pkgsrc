# $NetBSD: options.mk,v 1.2 2023/11/10 12:32:51 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fvwm3
PKG_SUPPORTED_OPTIONS=	svg

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msvg)
.  include "../../graphics/librsvg/buildlink3.mk"
.endif
