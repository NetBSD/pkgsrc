# $NetBSD: Makefile,v 1.4 2014/05/09 07:37:23 wiz Exp $

DISTNAME=	trytond_calendar-3.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/1}
CATEGORIES=	python time
MASTER_SITES=	http://downloads.tryton.org/3.2/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Calendar module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-python-sql-[0-9]*:../../databases/py-python-sql
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-pywebdav-[0-9]*:../../www/py-pywebdav
DEPENDS+=	${PYPKGPREFIX}-vobject-[0-9]*:../../textproc/py-vobject
DEPENDS+=	${PYPKGPREFIX}-trytond-[0-9]*:../../devel/py-trytond

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	26 33 34 # XXX according to setup.py (v3.0.2)
PYTHON_VERSIONED_DEPENDENCIES=	dateutil

REPLACE_PYTHON+=	tests/scenario_calendar.py tests/test_calendar.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
