# $NetBSD: Makefile,v 1.4 2020/01/18 23:35:45 rillig Exp $
TRYTON_MODULE_NAME=	trytond_web_user
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	python www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tryton.org/
COMMENT=	The web_user module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-party>=${TRYTON_BASEVER}:../../misc/py-trytond-party
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond
DEPENDS+=	${PYPKGPREFIX}-bcrypt-[0-9]*:../../security/py-bcrypt
DEPENDS+=	${PYPKGPREFIX}-html2text-[0-9]*:../../textproc/py-html2text

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
