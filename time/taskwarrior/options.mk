# $NetBSD: options.mk,v 1.1 2016/06/20 20:30:42 kamil Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.taskwarrior
PKG_SUPPORTED_OPTIONS=	lua
PKG_SUGGESTED_OPTIONS=	lua

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlua)
.include "../../lang/lua/buildlink3.mk"
.endif
