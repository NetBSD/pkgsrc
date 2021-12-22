# $NetBSD: Makefile,v 1.6 2021/12/22 22:54:56 mef Exp $
TRYTON_MODULE_NAME=	trytond_calendar_scheduling
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	python time

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tryton.org/
COMMENT=	Calendar scheduling module of Tryton's application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
#EPENDS+=	${PYPKGPREFIX}-pywebdav>=0.9.8:../../www/py-pywebdav
DEPENDS+=	${PYPKGPREFIX}-trytond-calendar>=${TRYTON_BASEVER}:../../time/py-trytond-calendar
#EPENDS+=	${PYPKGPREFIX}-trytond-webdav>=${TRYTON_BASEVER}:../../www/py-trytond-webdav
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

#YTHON_VERSIONS_ACCEPTED=	27 # py-pywebdav

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
