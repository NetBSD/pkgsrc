# $NetBSD: Makefile,v 1.19 2025/04/14 11:27:55 kim Exp $

DISTNAME=	yq-3.4.3
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yq/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kislyuk.github.io/yq/
COMMENT=	Command-line YAML and XML processor
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8.2.0nb1:../../devel/py-setuptools_scm
DEPENDS+=	jq-[0-9]*:../../devel/jq
DEPENDS+=	${PYPKGPREFIX}-argcomplete>=1.8.1:../../devel/py-argcomplete
DEPENDS+=	${PYPKGPREFIX}-tomlkit>=0.11.6:../../textproc/py-tomlkit
DEPENDS+=	${PYPKGPREFIX}-xmltodict>=0.11.0:../../textproc/py-xmltodict
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3.1:../../textproc/py-yaml
# noted in setup.py, but not actually needed
#TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
#TEST_DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
