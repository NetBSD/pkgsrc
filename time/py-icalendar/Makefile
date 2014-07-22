# $NetBSD: Makefile,v 1.19 2014/07/22 09:57:15 wiz Exp $

DISTNAME=	icalendar-3.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	http://pypi.python.org/packages/source/i/icalendar/

MAINTAINER=	mj@turner.org.za
HOMEPAGE=	http://icalendar.readthedocs.org/en/latest/
COMMENT=	Python parser/generator for iCalendar files, as per RFC2445
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

PYTHON_VERSIONED_DEPENDENCIES=  dateutil

USE_LANGUAGES=	# empty

# backup files in 3.8.1 distfile that are installed -- delete them before that happens
# https://github.com/collective/icalendar/issues/144
post-extract:
	${RM} ${WRKSRC}/src/icalendar/tests/test_unit_cal.py~
	${RM} ${WRKSRC}/src/icalendar/tests/test_fixed_issues.py~

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
