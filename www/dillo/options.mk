# $NetBSD: options.mk,v 1.6 2020/09/20 08:55:48 bsiegert Exp $

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

SUBST_CLASSES+=		sslcerts
SUBST_MESSAGE.sslcerts=	Fixing SSL certificate directory.
SUBST_FILES.sslcerts=	dpi/https.c
SUBST_STAGE.sslcerts=	post-extract
SUBST_SED.sslcerts=	-e 's,"/etc/ssl/certs,"${SSLCERTS},'

.else
CONFIGURE_ARGS+=	--disable-ssl
.endif
