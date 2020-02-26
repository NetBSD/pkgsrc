# $NetBSD: options.mk,v 1.1 2020/02/26 15:47:34 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.kitty
PKG_SUPPORTED_OPTIONS=		wayland

.include "../../devel/wayland/platform.mk"
.if ${PLATFORM_SUPPORTS_WAYLAND} == "yes"
PKG_SUGGESTED_OPTIONS=		wayland
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	wayland
.if !empty(PKG_OPTIONS:Mwayland)
PLIST.wayland=	yes
.  include "../../devel/wayland/buildlink3.mk"
.  include "../../devel/wayland-protocols/buildlink3.mk"
.endif
