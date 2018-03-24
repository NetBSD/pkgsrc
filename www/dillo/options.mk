# $NetBSD: options.mk,v 1.5 2018/03/24 15:40:07 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dillo
PKG_SUPPORTED_OPTIONS=	inet6 ssl
PKG_SUGGESTED_OPTIONS=	inet6 ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--enable-ssl
LIBS+=			-lssl
.include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif
