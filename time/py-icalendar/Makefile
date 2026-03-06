# $NetBSD: Makefile,v 1.59 2026/03/06 13:07:55 adam Exp $

DISTNAME=	icalendar-7.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/icalendar/}

MAINTAINER=	mj@turner.org.za
HOMEPAGE=	https://github.com/collective/icalendar
COMMENT=	Python parser/generator for iCalendar files, as per RFC2445
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs-[0-9]*:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-tzdata-[0-9]*:../../time/py-tzdata
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

USE_LANGUAGES=	# none

REPLACE_SH+=		src/icalendar/tests/fuzzed/generate_python_test_cases_from_downloaded_clusterfuzz_test_cases.sh
REPLACE_PYTHON+=	src/icalendar/cli.py

# as of 7.0.2
# 1 failed, 12085 passed, 23 skipped, 6 errors

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} icalendar icalendar-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
