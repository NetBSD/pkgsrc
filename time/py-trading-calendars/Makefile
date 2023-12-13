# $NetBSD: Makefile,v 1.10 2023/12/13 19:23:53 wiz Exp $

DISTNAME=	trading_calendars-2.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/trading-calendars/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/quantopian/trading_calendars
COMMENT=	Securities exchange calendars used by Zipline
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas-[0-9]*:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-toolz-[0-9]*:../../devel/py-toolz

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/tcal \
		${DESTDIR}${PREFIX}/bin/tcal-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
