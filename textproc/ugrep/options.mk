# $NetBSD: options.mk,v 1.2 2022/07/01 19:35:45 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ugrep
PKG_SUPPORTED_OPTIONS=	cpu-optimization boost-libs
PKG_SUGGESTED_OPTIONS=	cpu-optimization boost-libs

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
