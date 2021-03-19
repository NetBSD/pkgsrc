# $NetBSD: Makefile,v 1.14 2021/03/19 09:09:50 adam Exp $

DISTNAME=	django-treebeard-4.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-treebeard/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/django-treebeard/django-treebeard
COMMENT=	Efficient tree implementations for the Django Web Framework
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-django>=2.2:../../www/py-django2

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
