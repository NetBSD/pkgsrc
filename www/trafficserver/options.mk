# $NetBSD: options.mk,v 1.1 2017/08/17 14:57:09 fhajny Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.trafficserver
PKG_SUPPORTED_OPTIONS=		wccp
PKG_SUGGESTED_OPTIONS=		#

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		wccp

.if !empty(PKG_OPTIONS:Mwccp)
CONFIGURE_ARGS+=	--enable-wccp
PLIST.wccp=		yes
.endif
