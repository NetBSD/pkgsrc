# $NetBSD: options.mk,v 1.3 2026/01/25 09:33:36 kikadf Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rofi
PKG_SUPPORTED_OPTIONS=	wayland

.include "../../devel/wayland/platform.mk"

.if ${PLATFORM_SUPPORTS_WAYLAND} == "yes"
PKG_SUGGESTED_OPTIONS+=	wayland
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mwayland)
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.endif
