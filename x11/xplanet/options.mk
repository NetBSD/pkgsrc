# $NetBSD: options.mk,v 1.1 2009/07/22 13:37:06 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xplanet
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
USE_TOOLS+=	pkg-config

.include "../../devel/pango/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pango
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--without-xscreensaver
.endif
