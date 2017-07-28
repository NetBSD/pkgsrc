# $NetBSD: Makefile,v 1.3 2017/07/28 07:16:28 adam Exp $

DISTNAME=	iso8601-0.1.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/iso8601/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/iso8601/
COMMENT=	Simple Python module to parse ISO 8601 dates
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX} --verbose iso8601

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
