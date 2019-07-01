# $NetBSD: options.mk,v 1.1 2019/07/01 16:06:55 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocaml-mtime
PKG_SUPPORTED_OPTIONS=	js_of_ocaml
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	js_of_ocaml

###
### js_of_ocaml support
###
.if !empty(PKG_OPTIONS:Mjs_of_ocaml)
.include "../../devel/js_of_ocaml/buildlink3.mk"
PLIST.js_of_ocaml=	yes
OCAML_TOPKG_FLAGS+=	--with-js_of_ocaml true
.else
OCAML_TOPKG_FLAGS+= --with-js_of_ocaml false
.endif
