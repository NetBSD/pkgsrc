# $NetBSD: options.mk,v 1.2 2023/05/17 17:39:43 osa Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.unit
PKG_SUPPORTED_OPTIONS=	debug inet6 njs pcre pcre2 ssl
PKG_SUGGESTED_OPTIONS=	inet6 pcre2 ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--debug
.endif

.if empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--no-ipv6
.endif

.if !empty(PKG_OPTIONS:Mnjs)
USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	--njs
CONFIGURE_ARGS+=	--cc-opt="-I${PREFIX}/include"
CONFIGURE_ARGS+=	--ld-opt="-I${PREFIX}/lib"
.include "../../devel/libnjs/buildlink3.mk"
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
