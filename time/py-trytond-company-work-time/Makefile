# $NetBSD: Makefile,v 1.1 2015/08/24 14:49:45 richard Exp $
TRYTON_MODULE_NAME=	trytond_company_work_time
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	python time

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Company work time module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-company-[0-9]*:../../misc/py-trytond-company
DEPENDS+=	${PYPKGPREFIX}-trytond-[0-9]*:../../devel/py-trytond

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	tests/test_company_work_time.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
