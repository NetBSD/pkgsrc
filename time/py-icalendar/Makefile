# $NetBSD: Makefile,v 1.11 2013/02/16 18:08:48 wiz Exp $
#

DISTNAME=	icalendar-3.3
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	http://pypi.python.org/packages/source/i/icalendar/

MAINTAINER=	mj@turner.org.za
HOMEPAGE=	http://icalendar.readthedocs.org/en/latest/
COMMENT=	Python parser/generator for iCalendar files, as per RFC2445
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil

USE_LANGUAGES=	# empty

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
