# $NetBSD: Makefile,v 1.29 2020/08/20 11:37:06 joerg Exp $

DISTNAME=	djangorestframework-3.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/djangorestframework/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://django-rest-framework.org/
COMMENT=	Lightweight REST framework for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=1.11:../../www/py-django

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # since 3.10.0

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
