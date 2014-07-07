# $NetBSD: Makefile,v 1.2 2014/07/07 05:55:13 obache Exp $

DISTNAME=	WTForms-Alchemy-0.12.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	databases python www
MASTER_SITES=	https://pypi.python.org/packages/source/W/WTForms-Alchemy/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/kvesteri/wtforms-alchemy
COMMENT=	Generates WTForms forms from SQLAlchemy models
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.8.0:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-wtforms>=1.0.4:../../www/py-wtforms
DEPENDS+=	${PYPKGPREFIX}-wtforms-components>=0.9.2:../../www/py-wtforms-components
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy-utils>=0.23.1:../../databases/py-sqlalchemy-utils
DEPENDS+=	${PYPKGPREFIX}-six>=1.4.1:../../lang/py-six
.include "../../lang/python/pyversion.mk"
.if ${PYPKGPREFIX} == "py26"
DEPENDS+=	${PYPKGPREFIX}-ordereddict>=1.1:../../devel/py-ordereddict
.endif

USE_LANGUAGES=	# none

EGG_NAME=	${DISTNAME:S/-/_/1}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
