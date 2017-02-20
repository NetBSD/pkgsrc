# $NetBSD: Makefile,v 1.2 2017/02/20 17:00:37 wiz Exp $
TRYTON_MODULE_NAME=	trytond_calendar_scheduling
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	python time

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Calendar scheduling module of Tryton's application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-pywebdav>=0.9.8:../../www/py-pywebdav
DEPENDS+=	${PYPKGPREFIX}-trytond-calendar>=${TRYTON_BASEVER}:../../time/py-trytond-calendar
DEPENDS+=	${PYPKGPREFIX}-trytond-webdav>=${TRYTON_BASEVER}:../../www/py-trytond-webdav
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
