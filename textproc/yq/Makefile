# $NetBSD: Makefile,v 1.10 2023/02/23 19:33:15 wiz Exp $

DISTNAME=	yq-3.1.1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yq/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kislyuk.github.io/yq/
COMMENT=	Command-line YAML and XML processor
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	jq-[0-9]*:../../devel/jq
DEPENDS+=	${PYPKGPREFIX}-argcomplete>=1.8.1:../../devel/py-argcomplete
DEPENDS+=	${PYPKGPREFIX}-toml>=0.10.0:../../textproc/py-toml
DEPENDS+=	${PYPKGPREFIX}-xmltodict>=0.11.0:../../textproc/py-xmltodict
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3.1:../../textproc/py-yaml
# noted in setup.py, but not actually needed
#TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
#TEST_DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
#TEST_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} test/test.py -v

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
