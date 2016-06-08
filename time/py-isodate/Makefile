# $NetBSD: Makefile,v 1.2 2016/06/08 17:43:43 wiz Exp $

DISTNAME=	isodate-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python time
MASTER_SITES=	${MASTER_SITE_PYPI:=i/isodate/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://cheeseshop.python.org/pypi/isodate
COMMENT=	ISO 8601 date/time/duration parser and formatter
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}/src/isodate/tests; ${SETENV} ${TEST_ENV} ${PYTHONBIN} __init__.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
