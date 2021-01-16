# $NetBSD: Makefile,v 1.14 2021/01/16 09:02:05 adam Exp $

DISTNAME=	django-sekizai-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-sekizai/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/ojii/django-sekizai
COMMENT=	Django Template Blocks with extra functionality
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=2.2:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-classy-tags>=1.0:../../www/py-django-classy-tags

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
