# $NetBSD: Makefile,v 1.3 2020/03/21 12:56:46 adam Exp $

DISTNAME=	maya-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/maya/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kennethreitz/maya
COMMENT=	Human-friendly date and time handling
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-dateparser>=0.7.0:../../time/py-dateparser
DEPENDS+=	${PYPKGPREFIX}-humanize-[0-9]*:../../textproc/py-humanize
DEPENDS+=	${PYPKGPREFIX}-pendulum>=2.0.2:../../time/py-pendulum
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-snaptime-[0-9]*:../../time/py-snaptime
DEPENDS+=	${PYPKGPREFIX}-tzlocal-[0-9]*:../../time/py-tzlocal

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-humanize

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
