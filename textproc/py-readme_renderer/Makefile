# $NetBSD: Makefile,v 1.2 2020/04/23 05:53:00 adam Exp $

DISTNAME=	readme_renderer-26.0
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
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
