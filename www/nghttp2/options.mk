# $NetBSD: options.mk,v 1.8 2020/03/30 13:54:29 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nghttp2
PKG_SUPPORTED_OPTIONS=	nghttp2-asio

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	asio

###
### Build the ASIO C++ library
###
.if !empty(PKG_OPTIONS:Mnghttp2-asio)
# Upstream documents C++14 and gcc>=6 or clang>=6
USE_LANGUAGES+=		c++14
GCC_REQD+=		6
CONFIGURE_ARGS+=	--enable-asio-lib
CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_PREFIX.boost-libs}
CONFIGURE_ARGS+=	--with-boost-asio
CONFIGURE_ARGS+=	--with-boost-system
CONFIGURE_ARGS+=	--with-boost-thread
PLIST.asio=		yes
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-boost=no
.endif
