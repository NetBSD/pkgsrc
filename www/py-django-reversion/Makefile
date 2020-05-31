# $NetBSD: Makefile,v 1.23 2020/05/31 20:45:17 joerg Exp $

DISTNAME=	django-reversion-2.0.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-reversion/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/etianen/django-reversion/
COMMENT=	Version control facilities for Django
LICENSE=	modified-bsd

# django-3 removed django.utils.six
DEPENDS+=	${PYPKGPREFIX}-django>=1.8<3:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
