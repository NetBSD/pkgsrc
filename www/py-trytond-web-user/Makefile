# $NetBSD: Makefile,v 1.8 2025/02/18 15:32:11 wiz Exp $
TRYTON_MODULE_NAME=	trytond_web_user
PKGREVISION= 2
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	www python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tryton.org/
COMMENT=	The web_user module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-party>=${TRYTON_BASEVER}:../../misc/py-trytond-party
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond
DEPENDS+=	${PYPKGPREFIX}-html2text-[0-9]*:../../textproc/py-html2text

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	bcrypt
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
