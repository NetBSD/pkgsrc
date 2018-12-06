# $NetBSD: Makefile,v 1.1 2018/12/06 19:25:34 adam Exp $

DISTNAME=	aniso8601-4.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aniso8601/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucet.org/nielsenb/aniso8601
COMMENT=	Library for parsing ISO 8601 strings
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.6.1:../../time/py-dateutil
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=2.0.0:../../devel/py-mock

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}/aniso8601/tests && ${PYTHONBIN} -m unittest discover -v

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
