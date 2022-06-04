# $NetBSD: Makefile,v 1.1 2022/06/04 10:01:02 jaapb Exp $

GITHUB_PROJECT=	ocsigen-ppx-rpc
DISTNAME=	${GITHUB_PROJECT}-1.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocsigen/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocsigen/ocsigen-ppx-rpc/
COMMENT=	OCaml PPX extension for Ocsigen RPCs
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-ppxlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
