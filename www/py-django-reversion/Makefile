# $NetBSD: Makefile,v 1.20 2017/12/10 08:56:29 adam Exp $

DISTNAME=	django-reversion-2.0.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-reversion/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/etianen/django-reversion/
COMMENT=	Version control facilities for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=1.8:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
