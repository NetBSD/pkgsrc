# $NetBSD: Makefile,v 1.5 2017/07/11 08:18:43 adam Exp $

DISTNAME=	pyquery-1.2.17
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyquery/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/gawel/pyquery
COMMENT=	Python jquery-like library
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-lxml>=2.1:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-cssselect>0.7.9:../../textproc/py-cssselect
# circular dependency
#BUILD_DEPENDS+=	${PYPKGPREFIX}-WebTest-[0-9]*:../../www/py-WebTest

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PREFIX}/bin/py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
