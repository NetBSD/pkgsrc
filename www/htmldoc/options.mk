# $NetBSD: options.mk,v 1.5 2019/10/18 11:02:13 micha Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.htmldoc
PKG_SUPPORTED_OPTIONS=		ssl
PKG_SUGGESTED_OPTIONS=		ssl

.include "../../mk/bsd.options.mk"

###
### SSL support
###
.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--enable-ssl
.  include "../../security/gnutls/buildlink3.mk"
.  include "../../security/gnutls/libgnutls-config.mk"
CONFIGURE_ARGS+=	--enable-gnutls
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif
