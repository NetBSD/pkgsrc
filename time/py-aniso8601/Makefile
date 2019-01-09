# $NetBSD: Makefile,v 1.2 2019/01/09 09:01:08 adam Exp $

DISTNAME=	aniso8601-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aniso8601/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/nielsenb/aniso8601
COMMENT=	Library for parsing ISO 8601 strings
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.6.1:../../time/py-dateutil
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=2.0.0:../../devel/py-mock

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}/aniso8601/tests && ${PYTHONBIN} -m unittest discover -v

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
