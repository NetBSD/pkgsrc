# $NetBSD: Makefile,v 1.1 2017/09/29 08:47:53 wiz Exp $

DISTNAME=	ligotimegps-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/ligotimegps/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/ligotimegps/
COMMENT=	Pure-python version of lal.LIGOTimeGPS
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
