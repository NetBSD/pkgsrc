# $NetBSD: options.mk,v 1.1 2007/10/16 17:12:23 bjs Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.links
PKG_SUPPORTED_OPTIONS=	bzip2 links-zlib
PKG_SUGGESTED_OPTIONS=	bzip2 links-zlib

.include "../../mk/bsd.options.mk"

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
