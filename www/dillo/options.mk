# $NetBSD: options.mk,v 1.9 2025/01/31 14:33:17 micha Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dillo
PKG_SUPPORTED_OPTIONS=	inet6 tls libwebp
PKG_SUGGESTED_OPTIONS=	inet6 tls libwebp

.include "../../mk/bsd.options.mk"

# Support for IPv6 protocol
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

# Support for Transport Layer Security (TLS)
.if !empty(PKG_OPTIONS:Mtls)
CONFIGURE_ARGS+=	--enable-tls
CONFIGURE_ARGS+=	--disable-mbedtls
CONFIGURE_ARGS+=	--enable-openssl
CONFIGURE_ARGS+=	--with-ca-certs-dir=${SSLCERTS}
LIBS+=			-lssl
.include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-tls
CONFIGURE_ARGS+=	--disable-mbedtls
CONFIGURE_ARGS+=	--disable-openssl
.endif

.if !empty(PKG_OPTIONS:Mlibwebp)
CONFIGURE_ARGS+=	--enable-webp
.include "../../graphics/libwebp/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-webp
.endif
