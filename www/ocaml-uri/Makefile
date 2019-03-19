# $NetBSD: Makefile,v 1.1 2019/03/19 14:26:38 jaapb Exp $

GITHUB_PROJECT=	ocaml-uri
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-2.2.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mirage/ocaml-uri/
COMMENT=	RFC3986 URI parsing library for OCaml
LICENSE=	isc

USE_LANGUAGES=	# none

OCAML_USE_DUNE=	yes

.include "../../devel/ocaml-ppx_sexp_conv/buildlink3.mk"
.include "../../devel/ocaml-re/buildlink3.mk"
.include "../../devel/ocaml-sexplib0/buildlink3.mk"
.include "../../devel/ocaml-stringext/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
