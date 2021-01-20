# $NetBSD: Makefile,v 1.31 2021/01/20 10:57:01 adam Exp $

DISTNAME=	djangorestframework-3.12.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/djangorestframework/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://django-rest-framework.org/
COMMENT=	Lightweight REST framework for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=2.2:../../www/py-django2

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # since 3.10.0

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
