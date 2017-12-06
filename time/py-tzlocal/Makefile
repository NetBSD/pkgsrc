# $NetBSD: Makefile,v 1.4 2017/12/06 12:21:02 adam Exp $

DISTNAME=	tzlocal-1.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tzlocal/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/tzlocal
COMMENT=	Python tzinfo object for the local timezone
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
