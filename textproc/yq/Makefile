# $NetBSD: Makefile,v 1.7 2022/02/20 12:48:48 fcambus Exp $

DISTNAME=	yq-2.13.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=kislyuk/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kislyuk.github.io/yq/
COMMENT=	Command-line YAML and XML processor
LICENSE=	apache-2.0

DEPENDS+=	jq-[0-9]*:../../devel/jq

DEPENDS+=	${PYPKGPREFIX}-argcomplete-[0-9]*:../../devel/py-argcomplete
DEPENDS+=	${PYPKGPREFIX}-xmltodict-[0-9]*:../../textproc/py-xmltodict
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-toml-[0-9]*:../../textproc/py-toml

# XXX test dysfunctional
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage

PYTHON_VERSIONED_DEPENDENCIES+=	flake8:test

USE_PKG_RESOURCES=	yes

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
