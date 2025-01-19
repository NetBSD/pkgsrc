# $NetBSD: options.mk,v 1.8 2025/01/19 15:34:43 ktnb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dillo
PKG_SUPPORTED_OPTIONS=	inet6 ssl webp
PKG_SUGGESTED_OPTIONS=	inet6 ssl webp

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--enable-tls
LIBS+=			-lssl
.include "../../security/openssl/buildlink3.mk"

SUBST_CLASSES+=		sslcerts
SUBST_MESSAGE.sslcerts=	Fixing SSL certificate directory.
SUBST_FILES.sslcerts=	src/IO/tls_openssl.c src/IO/tls_mbedtls.c
SUBST_STAGE.sslcerts=	post-extract
SUBST_SED.sslcerts=	-e 's,"/etc/ssl/certs,"${SSLCERTS},'

.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if !empty(PKG_OPTIONS:Mwebp)
CONFIGURE_ARGS+=	--enable-webp
.include "../../graphics/libwebp/buildlink3.mk"
.endif
