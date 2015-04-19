# $NetBSD: Makefile,v 1.1 2015/04/19 21:27:58 rodent Exp $

DISTNAME=	isodate-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python time
MASTER_SITES=	https://pypi.python.org/packages/source/i/isodate/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://cheeseshop.python.org/pypi/isodate
COMMENT=	ISO 8601 date/time/duration parser and formatter
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}/src/isodate/tests; ${SETENV} ${TEST_ENV} ${PYTHONBIN} __init__.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
