# $NetBSD: Makefile,v 1.3 2020/01/18 23:35:38 rillig Exp $
TRYTON_MODULE_NAME=	trytond_calendar_classification
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	python time

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tryton.org/
COMMENT=	Calendar classification module of Tryton's application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-vobject>=0.8.0:../../textproc/py-vobject
DEPENDS+=	${PYPKGPREFIX}-trytond-calendar>=${TRYTON_BASEVER}:../../time/py-trytond-calendar
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
