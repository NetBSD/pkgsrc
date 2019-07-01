# $NetBSD: options.mk,v 1.1 2019/07/01 15:48:53 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocaml-cohttp
PKG_SUPPORTED_OPTIONS=	async lwt js_of_ocaml
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	lwt jsoo

###
### async support
###
.if !empty(PKG_OPTIONS:Masync)
DUNE_BUILD_PACKAGES+=	cohttp-async
.endif

###
### lwt support
###
.if !empty(PKG_OPTIONS:Mlwt)
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../misc/ocaml-magic-mime/buildlink3.mk"
PLIST.lwt=	yes
DUNE_BUILD_PACKAGES+=	cohttp-lwt cohttp-lwt-unix
OPAM_INSTALL_FILES+=	cohttp-lwt cohttp-lwt-unix
.endif

###
### js_of_ocaml support
###
.if !empty(PKG_OPTIONS:Mjs_of_ocaml)
.include "../../devel/js_of_ocaml/buildlink3.mk"
PLIST.jsoo=	yes
DUNE_BUILD_PACKAGES+=	cohttp-lwt-jsoo
OPAM_INSTALL_FILES+=	cohttp-lwt-jsoo
.endif
