# $NetBSD: Makefile,v 1.5 2026/10/25 01:43:03 alnsn Exp $

GITHUB_PROJECT=	ocsigen-ppx-rpc
DISTNAME=	${GITHUB_PROJECT}-1.0
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocsigen/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ocsigen/ocsigen-ppx-rpc/
COMMENT=	OCaml PPX extension for Ocsigen RPCs
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-ppxlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
