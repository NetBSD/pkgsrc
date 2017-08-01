# $NetBSD: Makefile,v 1.24 2017/08/01 18:12:38 kleink Exp $

DISTNAME=	vobject-0.9.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/vobject/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://eventable.github.io/vobject/
COMMENT=	Python iCalendar (ics) and vCard library
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} change_tz change_tz-${PYVERSSUFFIX} && \
		${MV} ics_diff ics_diff-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} tests.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
