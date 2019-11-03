# $NetBSD: options.mk,v 1.5 2019/11/03 09:14:07 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.aterm
PKG_SUPPORTED_OPTIONS=	aterm-big5 aterm-greek aterm-kanji aterm-xterm-scroll \
			afterstep

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mafterstep)
.include "../../graphics/tiff/buildlink3.mk"
.include "../../wm/afterstep/buildlink3.mk"
LDFLAGS.NetBSD+=-lexecinfo
.else
CONFIGURE_ARGS+=--without-afterimage_config --without-afterstep_config
.endif

.if !empty(PKG_OPTIONS:Materm-big5)
CONFIGURE_ARGS+=	--enable-big5
.endif

.if !empty(PKG_OPTIONS:Materm-greek)
CONFIGURE_ARGS+=	--enable-greek
.endif

.if !empty(PKG_OPTIONS:Materm-kanji)
CONFIGURE_ARGS+=	--enable-kanji
.endif

.if !empty(PKG_OPTIONS:Materm-xterm-scroll)
CONFIGURE_ARGS+=	--enable-xterm-scroll
.endif
