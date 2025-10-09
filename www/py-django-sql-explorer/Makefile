# $NetBSD: Makefile,v 1.14 2025/10/09 08:01:59 wiz Exp $

DISTNAME=	django_sql_explorer-5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-sql-explorer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/epantry/django-sql-explorer
COMMENT=	Pluggable app that allows to execute SQL, view, and export the results
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cryptography>=42.0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-django>=3.2:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-cryptography-django5>=2.2:../../security/py-django-cryptography-django5
DEPENDS+=	${PYPKGPREFIX}-requests>=2.2:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-sqlparse>=0.4.0:../../databases/py-sqlparse

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
