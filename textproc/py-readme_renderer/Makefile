# $NetBSD: Makefile,v 1.10 2023/06/28 08:57:58 wiz Exp $

DISTNAME=	readme_renderer-40.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/readme_renderer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/readme_renderer
COMMENT=	Library for rendering "readme" descriptions for Warehouse
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-bleach>=2.1.0:../../www/py-bleach
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.13.1:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.5.1:../../textproc/py-pygments
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 37

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
