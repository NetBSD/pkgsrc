# $NetBSD: Makefile,v 1.1 2023/06/17 17:52:23 wiz Exp $

DISTNAME=	plaster_pastedeploy-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/plaster_pastedeploy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Pylons/plaster_pastedeploy
COMMENT=	Loader implementing the PasteDeploy syntax to be used by plaster
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-plaster>=0.5:../../devel/py-plaster
DEPENDS+=	${PYPKGPREFIX}-PasteDeploy>=2.0:../../www/py-PasteDeploy
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# needs to be installed
TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
