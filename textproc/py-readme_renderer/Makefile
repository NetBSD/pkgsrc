# $NetBSD: Makefile,v 1.4 2020/11/02 14:47:57 adam Exp $

DISTNAME=	readme_renderer-28.0
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
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

PYTHON_VERSIONED_DEPENDENCIES=	test:test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
