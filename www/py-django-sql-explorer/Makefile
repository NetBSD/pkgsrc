# $NetBSD: Makefile,v 1.7 2023/12/07 18:10:26 adam Exp $

DISTNAME=	django-sql-explorer-3.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-sql-explorer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/epantry/django-sql-explorer
COMMENT=	Pluggable app that allows to execute SQL, view, and export the results
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-django>=3.2.12:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-sqlparse>=0.4.0:../../databases/py-sqlparse

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
