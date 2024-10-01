# $NetBSD: Makefile,v 1.30 2024/10/01 20:17:02 adam Exp $

DISTNAME=	vobject-0.9.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/vobject/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://py-vobject.github.io/
COMMENT=	Python iCalendar (ics) and vCard library
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.7.0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-pytz>0:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-six>0:../../lang/py-six

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} change_tz change_tz-${PYVERSSUFFIX} && \
		${MV} ics_diff ics_diff-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} tests.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
