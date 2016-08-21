# $NetBSD: options.mk,v 1.3 2016/08/21 09:53:55 bsiegert Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wwwoffle
PKG_SUPPORTED_OPTIONS=	inet6 gnutls libgcrypt
PKG_SUGGESTED_OPTIONS=	inet6 gnutls libgcrypt
# Note: gcrypt is needed for some SSL/HTTPS Features!
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+= --with-ipv6
.endif

.if !empty(PKG_OPTIONS:Mgnutls)
CONFIGURE_ARGS+= --with-gnutls=${BUILDLINK_DIR}
BUILDLINK_ABI_DEPENDS.gnutls+= gnutls>=3.0
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gnutls/libgnutls-config.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibgcrypt)
BUILDLINK_API_DEPENDS.libgcrypt+= libgcrypt>=1.2.0
.include "../../security/libgcrypt/buildlink3.mk"
.endif
