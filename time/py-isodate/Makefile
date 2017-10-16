# $NetBSD: Makefile,v 1.4 2017/10/16 06:44:28 adam Exp $

DISTNAME=	isodate-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python time
MASTER_SITES=	${MASTER_SITE_PYPI:=i/isodate/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://cheeseshop.python.org/pypi/isodate
COMMENT=	ISO 8601 date/time/duration parser and formatter
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}/src/isodate/tests && ${SETENV} ${TEST_ENV} ${PYTHONBIN} __init__.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
