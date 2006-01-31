# $NetBSD: options.mk,v 1.3 2006/01/31 11:44:53 joerg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xterm
PKG_SUPPORTED_OPTIONS=	xterm-luit freetype
PKG_OPTIONS_OPTIONAL_GROUPS=	color
PKG_OPTIONS_GROUP.color=	xterm-88color xterm-256color
PKG_SUGGESTED_OPTIONS=	xterm-256color xterm-luit

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mxterm-88color)
CONFIGURE_ARGS+= --enable-88-color
.endif

.if !empty(PKG_OPTIONS:Mxterm-256color)
CONFIGURE_ARGS+= --enable-256-color
.endif

.if !empty(PKG_OPTIONS:Mxterm-luit)
CONFIGURE_ARGS+= --enable-luit
.endif

.if !empty(PKG_OPTIONS:Mfreetype)
CONFIGURE_ARGS+= --enable-freetype

.include "../../fonts/Xft2/buildlink3.mk"
.endif

