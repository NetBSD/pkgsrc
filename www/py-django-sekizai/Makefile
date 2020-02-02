# $NetBSD: Makefile,v 1.13 2020/02/02 06:47:17 adam Exp $

DISTNAME=	django-sekizai-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-sekizai/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/ojii/django-sekizai
COMMENT=	Django Template Blocks with extra functionality
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=1.11:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-classy-tags>=0.9.0:../../www/py-django-classy-tags

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
