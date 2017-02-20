# $NetBSD: Makefile,v 1.8 2017/02/20 17:00:37 wiz Exp $
TRYTON_MODULE_NAME=	trytond_calendar
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	python time

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Calendar module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-python-sql-[0-9]*:../../databases/py-python-sql
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-pywebdav-[0-9]*:../../www/py-pywebdav
DEPENDS+=	${PYPKGPREFIX}-vobject-[0-9]*:../../textproc/py-vobject
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	tests/scenario_calendar.py tests/test_calendar.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
