# $NetBSD: Makefile,v 1.3 2018/12/05 15:57:48 adam Exp $

DISTNAME=	ligotimegps-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/ligotimegps/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gwpy/ligotimegps
COMMENT=	Pure-python version of lal.LIGOTimeGPS
LICENSE=	gnu-lgpl-v3

TEST_DEPENDS+=	${PYPKGPREFIX}-test>=2.8:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
