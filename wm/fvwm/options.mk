# $NetBSD: options.mk,v 1.11 2023/01/18 07:43:16 vins Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.fvwm
PKG_SUPPORTED_OPTIONS=		xrender xcursor xft2 fribidi debug svg
PKG_SUPPORTED_OPTIONS+=		doc
PKG_SUGGESTED_OPTIONS+=		svg xft2 xrender xcursor doc

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		doc

.if !empty(PKG_OPTIONS:Mxcursor)
CONFIGURE_ARGS+=	--enable-xcursor
.include "../../x11/libXcursor/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-xcursor
.endif

.if !empty(PKG_OPTIONS:Mxft2)
CONFIGURE_ARGS+=        --enable-xft
.include "../../x11/libXft/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --disable-xft
.endif

.if !empty(PKG_OPTIONS:Mxrender)
CONFIGURE_ARGS+=        --enable-xrender
.include "../../x11/libXrender/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --disable-xrender
.endif

.if !empty(PKG_OPTIONS:Mfribidi)
CONFIGURE_ARGS+=	--enable-bidi
.include "../../converters/fribidi/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-bidi
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug-msgs
.else
CONFIGURE_ARGS+=	--disable-debug-msgs
.endif

.if !empty(PKG_OPTIONS:Msvg)
.include "../../graphics/librsvg/available.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-rsvg
.endif

.if !empty(PKG_OPTIONS:Mdoc)
# 2 manpages want xsltproc.
CONFIGURE_ARGS+=	--enable-mandoc
TOOL_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl
TOOL_DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt
PLIST.doc=		yes
.else
CONFIGURE_ARGS+=	--disable-mandoc
.endif
