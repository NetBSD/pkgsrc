# $NetBSD: options.mk,v 1.1 2025/08/31 14:46:24 taca Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.contao

PKG_OPTIONS_REQUIRED_GROUPS=	imaging
PKG_OPTIONS_GROUP.imaging=	imagemagick graphicsmagick
PKG_SUGGESTED_OPTIONS=		imagemagick

.include "../../mk/bsd.options.mk"

###
### Use ImageMagick
###
.if !empty(PKG_OPTIONS:Mimagemagick)
DEPENDS+=	ImageMagick>=7.0.0:../../graphics/ImageMagick
.endif

###
### Use GraphicsMagick
###
.if !empty(PKG_OPTIONS:Mgraphicsmagick)
DEPENDS+=	GraphicsMagick>=1.3.0:../../graphics/GraphicsMagick
.endif
