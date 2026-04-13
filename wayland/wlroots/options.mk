# $NetBSD: options.mk,v 1.1 2026/04/13 17:20:09 kikadf Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wlroots
PKG_SUPPORTED_OPTIONS+=	xwayland
PKG_SUGGESTED_OPTIONS+=	xwayland

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	xwayland
.if !empty(PKG_OPTIONS:Mxwayland)
.include "../../wayland/xwayland/buildlink3.mk"
PLIST.xwayland=	yes
.endif
