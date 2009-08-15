# $NetBSD: options.mk,v 1.1 2009/08/15 14:48:34 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome-control-center
PKG_SUPPORTED_OPTIONS=	evolution
PKG_SUGGESTED_OPTIONS=	evolution

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		evolution

.if !empty(PKG_OPTIONS:Mevolution)
CONFIGURE_ARGS+=	--enable-aboutme
PLIST.evolution=	yes
.include "../../mail/evolution-data-server/buildlink3.mk"
.endif
