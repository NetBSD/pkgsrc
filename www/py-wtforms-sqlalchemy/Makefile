# $NetBSD: Makefile,v 1.2 2024/03/06 21:29:13 wiz Exp $

DISTNAME=	WTForms-SQLAlchemy-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/WTForms-SQLAlchemy/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/wtforms/wtforms-sqlalchemy
COMMENT=	WTForms integration for SQLAlchemy
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-wtforms>=1.0.5:../../www/py-wtforms
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.7.10:../../databases/py-sqlalchemy

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# empty

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
