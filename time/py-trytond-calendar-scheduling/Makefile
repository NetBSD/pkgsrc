# $NetBSD: Makefile,v 1.1 2016/12/04 21:13:08 rodent Exp $
TRYTON_MODULE_NAME=	trytond_calendar_scheduling
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	python time

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Calendar scheduling module of Tryton's application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-pywebdav>=0.9.8:../../www/py-pywebdav
DEPENDS+=	${PYPKGPREFIX}-trytond-calendar>=${TRYTON_BASEVER}:../../time/py-trytond-calendar
DEPENDS+=	${PYPKGPREFIX}-trytond-webdav>=${TRYTON_BASEVER}:../../www/py-trytond-webdav
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES=	dateutil

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
