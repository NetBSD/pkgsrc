# $NetBSD: options.mk,v 1.1 2020/01/24 14:07:02 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.lablgtk3
PKG_SUPPORTED_OPTIONS=	gtksourceview3 gtkspell
PKG_SUGGESTED_OPTIONS=	gtksourceview3 gtkspell
PLIST_VARS+=		gtkspell gtksourceview

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtkspell)
.include "../../textproc/gtkspell3/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gtkspell
PLIST.gtkspell=	yes
.else
CONFIGURE_ARGS+=	--without-gtkspell
.endif

.if !empty(PKG_OPTIONS:Mgtksourceview3)
.include "../../x11/gtksourceview3/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gtksourceview3
PLIST.gtksourceview=	yes
.else
CONFIGURE_ARGS+=	--without-gtksourceview3
.endif
