# $NetBSD: Makefile,v 1.4 2020/04/21 11:25:18 jaapb Exp $

GITHUB_PROJECT=	ocaml-cohttp
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-2.5.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mirage/ocaml-cohttp/
COMMENT=	OCaml library for HTTP clients and servers
LICENSE=	isc

USE_LANGUAGES=	# none

OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	cohttp cohttp-top
OPAM_INSTALL_FILES=	cohttp cohttp-top

.include "options.mk"
.include "../../devel/ocaml-base64/buildlink3.mk"
.include "../../devel/ocaml-fmt/buildlink3.mk"
.include "../../devel/ocaml-ppx_fields_conv/buildlink3.mk"
.include "../../devel/ocaml-ppx_sexp_conv/buildlink3.mk"
.include "../../devel/ocaml-re/buildlink3.mk"
.include "../../devel/ocaml-sexplib0/buildlink3.mk"
.include "../../devel/ocaml-stdlib-shims/buildlink3.mk"
.include "../../devel/ocaml-stringext/buildlink3.mk"
.include "../../net/ocaml-conduit/buildlink3.mk"
.include "../../textproc/ocaml-jsonm/buildlink3.mk"
.include "../../www/ocaml-uri/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
