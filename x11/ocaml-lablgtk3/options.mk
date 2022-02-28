# $NetBSD: options.mk,v 1.3 2022/02/28 13:16:24 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocaml-lablgtk3
PKG_SUPPORTED_OPTIONS=	gtksourceview3 gtkspell
PKG_SUGGESTED_OPTIONS=	gtksourceview3 gtkspell
PLIST_VARS+=		gtkspell gtksourceview

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtkspell)
.include "../../textproc/gtkspell3/buildlink3.mk"
PLIST.gtkspell=	yes
OCAML_FINDLIB_DIRS+=	lablgtk3-gtkspell3
.endif

.if !empty(PKG_OPTIONS:Mgtksourceview3)
.include "../../x11/gtksourceview3/buildlink3.mk"
PLIST.gtksourceview=	yes
OCAML_FINDLIB_DIRS+=	lablgtk3-sourceview3
.endif
