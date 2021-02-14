# $NetBSD: options.mk,v 1.1 2021/02/14 11:56:57 otis Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.unit
PKG_SUPPORTED_OPTIONS=	debug inet6 pcre pcre2 ssl
PKG_SUGGESTED_OPTIONS=	inet6 pcre2 ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--debug
.endif

.if empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--no-ipv6
.endif

.if empty(PKG_OPTIONS:Mpcre) && empty(PKG_OPTIONS:Mpcre2)
CONFIGURE_ARGS+=	--no-regex
.endif

.if !empty(PKG_OPTIONS:Mpcre)
CONFIGURE_ARGS+=	--no-pcre2
.include "../../devel/pcre/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpcre2)
.include "../../devel/pcre2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--openssl
.endif
