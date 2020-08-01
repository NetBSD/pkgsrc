# $NetBSD: options.mk,v 1.1 2020/08/01 15:13:59 scole Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ugrep
PKG_SUPPORTED_OPTIONS=	cpu-optimization boost-libs pcre2
PKG_SUGGESTED_OPTIONS=	cpu-optimization boost-libs pcre2

.include "../../mk/bsd.options.mk"

# XXX don't build with cpu optimizations detected during configure
.if empty(PKG_OPTIONS:Mcpu-optimization)
CONFIGURE_ARGS+=	--disable-avx
CONFIGURE_ARGS+=	--disable-sse2
CONFIGURE_ARGS+=	--disable-neon
.endif

.if !empty(PKG_OPTIONS:Mboost-libs)
CONFIGURE_ARGS+=	--with-boost-regex
.include "../../devel/boost-libs/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpcre2)
CONFIGURE_ARGS+=	--with-pcre2
.include "../../devel/pcre2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-pcre2
.endif
