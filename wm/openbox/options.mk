# $NetBSD: options.mk,v 1.1 2013/12/08 07:56:31 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openbox
PKG_SUPPORTED_OPTIONS=	imlib2 svg
PKG_SUGGESTED_OPTIONS=	imlib2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mimlib2)
.include "../../graphics/imlib2/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-imlib2
.else
CONFIGURE_ARGS+=	--disable-imlib2
.endif

.if !empty(PKG_OPTIONS:Msvg)
.include "../../graphics/librsvg/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-librsvg
.else
CONFIGURE_ARGS+=	--disable-librsvg
.endif
