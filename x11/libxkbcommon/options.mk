# $NetBSD: options.mk,v 1.1 2013/12/18 18:51:03 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libxkbcommon
PKG_SUPPORTED_OPTIONS=	doc

PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
BUILD_DEPENDS+= 	doxygen-[0-9]*:../../devel/doxygen
PLIST.doc=		yes
CONFIGURE_ARGS+= 	--enable-docs=yes
.else
CONFIGURE_ARGS+= 	--enable-docs=no
.endif
