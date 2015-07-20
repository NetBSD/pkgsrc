# $NetBSD: options.mk,v 1.3 2015/07/20 23:03:24 dholland Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.links
PKG_OPTIONS_LEGACY_OPTS+=	links-xz:lzma
PKG_OPTIONS_LEGACY_OPTS+=	links-zlib:zlib
PKG_SUPPORTED_OPTIONS+=		bzip2 lzma zlib
PKG_SUGGESTED_OPTIONS=		bzip2 lzma zlib

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlzma)
.  include "../../archivers/xz/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-lzma
.endif

.if !empty(PKG_OPTIONS:Mbzip2)
.  include "../../archivers/bzip2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-bzip2
.endif

.if !empty(PKG_OPTIONS:Mzlib)
.  include "../../devel/zlib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-zlib
.endif
