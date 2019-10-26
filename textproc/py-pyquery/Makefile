# $NetBSD: Makefile,v 1.9 2019/10/26 22:55:24 adam Exp $

DISTNAME=	pyquery-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyquery/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gawel/pyquery
COMMENT=	Python jquery-like library
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cssselect>0.7.9:../../textproc/py-cssselect
DEPENDS+=	${PYPKGPREFIX}-lxml>=2.1:../../textproc/py-lxml
TEST_DEPENDS+=	${PYPKGPREFIX}-WebTest-[0-9]*:../../www/py-WebTest

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
