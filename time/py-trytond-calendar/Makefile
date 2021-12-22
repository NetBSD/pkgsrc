# $NetBSD: Makefile,v 1.12 2021/12/22 22:54:55 mef Exp $
TRYTON_MODULE_NAME=	trytond_calendar
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	python time

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tryton.org/
COMMENT=	Calendar module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-python-sql-[0-9]*:../../databases/py-python-sql
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
#EPENDS+=	${PYPKGPREFIX}-pywebdav-[0-9]*:../../www/py-pywebdav
DEPENDS+=	${PYPKGPREFIX}-vobject-[0-9]*:../../textproc/py-vobject
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	tests/scenario_calendar.py tests/test_calendar.py

#YTHON_VERSIONS_ACCEPTED=	27 # py-pywebdav

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
