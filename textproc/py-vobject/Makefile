# $NetBSD: Makefile,v 1.22 2017/01/20 22:38:29 wiz Exp $

DISTNAME=	vobject-0.9.4
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
