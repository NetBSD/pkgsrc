# $NetBSD: Makefile,v 1.1 2022/05/25 15:38:10 kleink Exp $

DISTNAME=	WTForms-SQLAlchemy-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/WTForms-SQLAlchemy/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/wtforms/wtforms-sqlalchemy
COMMENT=	WTForms integration for SQLAlchemy
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-wtforms>=1.0.5:../../www/py-wtforms
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.7.10:../../databases/py-sqlalchemy

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
