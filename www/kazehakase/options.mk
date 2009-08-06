# $NetBSD: options.mk,v 1.5 2009/08/06 12:21:37 tnn Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.kazehakase
PKG_SUPPORTED_OPTIONS=	gnutls
PKG_SUGGESTED_OPTIONS+=	gnutls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls)
.  include "../../security/gnutls/buildlink3.mk"
.  include "../../security/gnutls/libgnutls-config.mk"
#CONFIGURE_ARGS+=	--enable-ssl
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif
