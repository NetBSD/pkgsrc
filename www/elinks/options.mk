# $NetBSD: options.mk,v 1.19 2023/04/14 21:35:06 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.felinks
PKG_OPTIONS_REQUIRED_GROUPS=	tls
PKG_OPTIONS_GROUP.tls=		gnutls openssl
PKG_SUGGESTED_OPTIONS=		gnutls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls)
.  include "../../security/gnutls/buildlink3.mk"
.  include "../../security/libgcrypt/buildlink3.mk"
CONFIGURE_ARGS+=	--without-openssl
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
.endif
