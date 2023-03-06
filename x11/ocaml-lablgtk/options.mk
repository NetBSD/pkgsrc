# $NetBSD: options.mk,v 1.4 2023/03/06 16:20:13 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.lablgtk
PKG_SUPPORTED_OPTIONS=	glade gtksourceview2 gtkspell svg
PKG_SUGGESTED_OPTIONS=	glade gtkspell svg

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mglade)
.include "../../devel/libglade/buildlink3.mk"
CONFIGURE_ARGS+=	--with-glade
PLIST_SRC+=		PLIST.glade
.else
CONFIGURE_ARGS+=	--without-glade
.endif

.if !empty(PKG_OPTIONS:Mgtkspell)
.include "../../textproc/gtkspell/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gtkspell
PLIST_SRC+=		PLIST.gtkspell
.else
CONFIGURE_ARGS+=	--without-gtkspell
.endif

.if !empty(PKG_OPTIONS:Mgtksourceview2)
.include "../../x11/gtksourceview2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gtksourceview2
PLIST_SRC+=		PLIST.gtksourceview2
.else
CONFIGURE_ARGS+=	--without-gtksourceview2
.endif

.if !empty(PKG_OPTIONS:Msvg)
.include "../../graphics/librsvg/buildlink3.mk"
CONFIGURE_ARGS+=	--with-rsvg
PLIST_SRC+=		PLIST.svg
.else
CONFIGURE_ARGS+=	--without-rsvg
.endif

PLIST_SRC+=	PLIST
