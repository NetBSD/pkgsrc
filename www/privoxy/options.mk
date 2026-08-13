# $NetBSD: options.mk,v 1.2 2026/08/13 18:17:58 wiz Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.privoxy
PKG_SUPPORTED_OPTIONS+=		inet6 zlib zstd
PKG_SUGGESTED_OPTIONS+=		inet6 zlib zstd

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6-support
.else
CONFIGURE_ARGS+=	--disable-ipv6-support
.endif

.if !empty(PKG_OPTIONS:Mzlib)
CONFIGURE_ARGS+=	--enable-zlib --enable-compression
.include "../../devel/zlib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-zlib --disable-compression
.endif

.if !empty(PKG_OPTIONS:Mzstd)
CONFIGURE_ARGS+=	--with-zstd
.include "../../archivers/zstd/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-zstd
.endif
