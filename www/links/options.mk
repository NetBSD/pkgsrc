# $NetBSD: options.mk,v 1.2 2012/01/27 08:24:28 sbd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.links
PKG_SUPPORTED_OPTIONS=	bzip2 links-zlib links-xz
PKG_SUGGESTED_OPTIONS=	bzip2 links-zlib links-xz

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlinks-xz)
.  include "../../archivers/xz/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-lzma
.endif

.if !empty(PKG_OPTIONS:Mbzip2)
.  include "../../archivers/bzip2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-bzip2
.endif

.if !empty(PKG_OPTIONS:Mlinks-zlib)
.  include "../../devel/zlib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-zlib
.endif
