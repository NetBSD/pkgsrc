# $NetBSD: Makefile,v 1.4 2022/01/04 20:55:13 wiz Exp $

DISTNAME=	trading_calendars-1.11.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/trading-calendars/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/quantopian/trading_calendars
COMMENT=	Securities exchange calendars used by Zipline
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-lru-dict-[0-9]*:../../devel/py-lru-dict
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas-[0-9]*:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-toolz-[0-9]*:../../devel/py-toolz

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-pandas

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/tcal \
		${DESTDIR}${PREFIX}/bin/tcal-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
