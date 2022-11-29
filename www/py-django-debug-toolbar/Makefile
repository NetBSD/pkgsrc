# $NetBSD: Makefile,v 1.4 2022/11/29 20:41:28 adam Exp $

DISTNAME=	django-debug-toolbar-3.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-debug-toolbar/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jazzband/django-debug-toolbar
COMMENT=	Debugging toolbar for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-sqlparse>=0.2.0:../../databases/py-sqlparse
DEPENDS+=	${PYPKGPREFIX}-django>=3.2.4:../../www/py-django3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
