# $NetBSD: options.mk,v 1.3 2007/10/27 13:03:50 wiz Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.kazehakase
PKG_SUPPORTED_OPTIONS=	gnutls
PKG_SUGGESTED_OPTIONS+=	gnutls

.include "../../www/seamonkey/gecko-options.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls)
.  include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ssl
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif
