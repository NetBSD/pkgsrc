# $NetBSD: Makefile,v 1.12 2024/11/11 07:29:20 wiz Exp $

DISTNAME=	django_sql_explorer-4.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-sql-explorer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/epantry/django-sql-explorer
COMMENT=	Pluggable app that allows to execute SQL, view, and export the results
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-django>=3.2:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-requests>=2.2:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-sqlparse>=0.4.0:../../databases/py-sqlparse

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
