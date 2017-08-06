# $NetBSD: Makefile,v 1.27 2017/08/06 19:30:51 adam Exp $

DISTNAME=	icalendar-3.11.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/icalendar/}

MAINTAINER=	mj@turner.org.za
HOMEPAGE=	http://icalendar.readthedocs.org/en/latest/
COMMENT=	Python parser/generator for iCalendar files, as per RFC2445
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

USE_LANGUAGES=	# empty

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
