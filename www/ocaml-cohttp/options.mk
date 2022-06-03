# $NetBSD: options.mk,v 1.4 2022/06/03 09:25:20 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocaml-cohttp
PKG_SUPPORTED_OPTIONS=	lwt js_of_ocaml # async
PKG_SUGGESTED_OPTIONS=	lwt js_of_ocaml # async

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	lwt jsoo # async

###
### async support
###
# doesn't work on NetBSD for the moment
#.if !empty(PKG_OPTIONS:Masync)
#.include "../../devel/ocaml-async/buildlink3.mk"
#.include "../../devel/ocaml-async_kernel/buildlink3.mk"
#.include "../../devel/ocaml-async_unix/buildlink3.mk"
#.include "../../devel/ocaml-base/buildlink3.mk"
#.include "../../devel/ocaml-core_unix/buildlink3.mk"
#.include "../../net/ocaml-ipaddr/buildlink3.mk"
#PLIST.async=		yes
#DUNE_BUILD_PACKAGES+=	cohttp-async
#OPAM_INSTALL_FILES+=	cohttp-async
#OCAML_FINDLIB_DIRS+=	cohttp-async
#.endif

###
### lwt support
###
.if !empty(PKG_OPTIONS:Mlwt)
.include "../../devel/ocaml-cmdliner/buildlink3.mk"
.include "../../devel/ocaml-fmt/buildlink3.mk"
.include "../../devel/ocaml-logs/buildlink3.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../misc/ocaml-magic-mime/buildlink3.mk"
.include "../../net/ocaml-conduit/buildlink3.mk"
PLIST.lwt=	yes
DUNE_BUILD_PACKAGES+=	cohttp-lwt cohttp-lwt-unix
OPAM_INSTALL_FILES+=	cohttp-lwt cohttp-lwt-unix
OCAML_FINDLIB_DIRS+=	cohttp-lwt cohttp-lwt-unix
.endif

###
### js_of_ocaml support
###
.if !empty(PKG_OPTIONS:Mjs_of_ocaml)
.include "../../devel/js_of_ocaml/buildlink3.mk"
PLIST.jsoo=	yes
DUNE_BUILD_PACKAGES+=	cohttp-lwt-jsoo
OPAM_INSTALL_FILES+=	cohttp-lwt-jsoo
OCAML_FINDLIB_DIRS+=	cohttp-lwt-jsoo
.endif
