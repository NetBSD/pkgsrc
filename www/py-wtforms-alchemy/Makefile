# $NetBSD: Makefile,v 1.11 2023/03/07 20:28:46 adam Exp $

DISTNAME=	WTForms-Alchemy-0.18.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/WTForms-Alchemy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kvesteri/wtforms-alchemy
COMMENT=	Generates WTForms forms from SQLAlchemy models
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.0:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy-utils>=0.32.6:../../databases/py-sqlalchemy-utils
DEPENDS+=	${PYPKGPREFIX}-wtforms>=2.2:../../www/py-wtforms
DEPENDS+=	${PYPKGPREFIX}-wtforms-components>=0.9.2:../../www/py-wtforms-components

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
