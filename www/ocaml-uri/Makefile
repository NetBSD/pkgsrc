# $NetBSD: Makefile,v 1.5 2022/05/24 18:59:36 jaapb Exp $

DISTNAME=	${GITHUB_PROJECT}-4.2.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}
GITHUB_PROJECT=	ocaml-uri
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mirage/ocaml-uri/
COMMENT=	RFC3986 URI parsing library for OCaml
LICENSE=	isc

USE_LANGUAGES=	# none

OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	uri uri-sexp
OPAM_INSTALL_FILES=	uri uri-sexp

.include "../../devel/ocaml-angstrom/buildlink3.mk"
.include "../../devel/ocaml-ppx_sexp_conv/buildlink3.mk"
.include "../../devel/ocaml-re/buildlink3.mk"
.include "../../devel/ocaml-sexplib0/buildlink3.mk"
.include "../../devel/ocaml-stringext/buildlink3.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
