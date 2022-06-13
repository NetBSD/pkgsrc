# $NetBSD: Makefile,v 1.1 2022/06/13 08:01:03 jaapb Exp $

PKGNAME=	ocaml-${DISTNAME}
DISTNAME=	${GITHUB_PROJECT}-4.2.0
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}
GITHUB_PROJECT=	mirage-clock
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	https://github.com/mirage/mirage-clock/
COMMENT=	Portable clock implementation
LICENSE=	isc

OCAML_USE_DUNE=	yes

DUNE_BUILD_PACKAGES=	mirage-clock mirage-clock-unix
OPAM_INSTALL_FILES=	${DUNE_BUILD_PACKAGES}
OCAML_FINDLIB_DIRS=	${DUNE_BUILD_PACKAGES}

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-dune-configurator/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
