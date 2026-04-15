# $NetBSD: options.mk,v 1.1 2026/04/15 10:07:17 kikadf Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dunst
PKG_SUPPORTED_OPTIONS=	wayland

.include "../../devel/wayland/platform.mk"

.if ${PLATFORM_SUPPORTS_WAYLAND} == "yes"
PKG_SUGGESTED_OPTIONS+=	wayland
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mwayland)
.include "../../devel/input-headers/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.else
MAKE_FLAGS+=	WAYLAND=0
.endif
