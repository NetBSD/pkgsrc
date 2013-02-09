# $NetBSD: Makefile,v 1.8 2013/02/09 16:36:12 kleink Exp $
#

DISTNAME=	icalendar-3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	http://pypi.python.org/packages/source/i/icalendar/

MAINTAINER=	mj@turner.org.za
HOMEPAGE=	http://icalendar.readthedocs.org/en/latest/
COMMENT=	Python parser/generator for iCalendar files, as per RFC2445
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

post-extract:
	${RM} ${WRKSRC}/src/icalendar/.cal.py.swp
	${RM} ${WRKSRC}/src/icalendar/.tools.py.swp

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
