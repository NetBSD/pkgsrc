# $NetBSD: options.mk,v 1.1 2020/09/29 12:22:35 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fvwm3
PKG_SUPPORTED_OPTIONS=	svg
PKG_SUGGESTED_OPTIONS=	svg

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msvg)
.  include "../../graphics/librsvg/buildlink3.mk"
.endif
