# $NetBSD: options.mk,v 1.1 2016/06/12 20:31:10 kamil Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rofi

PKG_SUPPORTED_OPTIONS=	i3
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mi3)
.include "../../wm/i3/buildlink3.mk"
.endif
