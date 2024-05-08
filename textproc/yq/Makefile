# $NetBSD: Makefile,v 1.17 2024/05/08 11:57:20 adam Exp $

DISTNAME=	yq-3.4.3
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yq/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kislyuk.github.io/yq/
COMMENT=	Command-line YAML and XML processor
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	jq-[0-9]*:../../devel/jq
DEPENDS+=	${PYPKGPREFIX}-argcomplete>=1.8.1:../../devel/py-argcomplete
DEPENDS+=	${PYPKGPREFIX}-tomlkit>=0.11.6:../../textproc/py-tomlkit
DEPENDS+=	${PYPKGPREFIX}-xmltodict>=0.11.0:../../textproc/py-xmltodict
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3.1:../../textproc/py-yaml
# noted in setup.py, but not actually needed
#TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
#TEST_DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
#TEST_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
