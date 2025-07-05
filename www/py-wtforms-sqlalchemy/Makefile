# $NetBSD: Makefile,v 1.5 2025/07/05 11:44:08 wiz Exp $

DISTNAME=	wtforms_sqlalchemy-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/WTForms-SQLAlchemy/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/wtforms/wtforms-sqlalchemy
COMMENT=	WTForms integration for SQLAlchemy
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.4:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-wtforms>=3.1:../../www/py-wtforms

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
