# $NetBSD: Makefile,v 1.6 2012/10/08 13:04:28 asau Exp $
#

DISTNAME=	icalendar-3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	http://pypi.python.org/packages/source/i/icalendar/

MAINTAINER=	mj@turner.org.za
HOMEPAGE=	http://codespeak.net/icalendar/
COMMENT=	Python parser/generator for iCalendar files, as per RFC2445
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
