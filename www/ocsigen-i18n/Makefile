# $NetBSD: Makefile,v 1.11 2022/06/04 08:43:55 wiz Exp $

GITHUB_PROJECT=	ocsigen-i18n
DISTNAME=	${GITHUB_PROJECT}-4.0.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=besport/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/besport/ocsigen-i18n/
COMMENT=	I18n package for Ocsigen
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		# none
OCAML_USE_DUNE=		yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-ppx_tools/buildlink3.mk"
.include "../../devel/ocaml-ppxlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
