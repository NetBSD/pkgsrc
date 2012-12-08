# $NetBSD: Makefile,v 1.7 2012/12/08 23:36:45 wiz Exp $
#

DISTNAME=	icalendar-3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	http://pypi.python.org/packages/source/i/icalendar/

MAINTAINER=	mj@turner.org.za
HOMEPAGE=	http://icalendar.readthedocs.org/en/latest/
COMMENT=	Python parser/generator for iCalendar files, as per RFC2445
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

post-extract:
	${RM} ${WRKSRC}/src/icalendar/.cal.py.swp
	${RM} ${WRKSRC}/src/icalendar/.tools.py.swp

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
