# $NetBSD: Makefile,v 1.14 2016/09/07 13:41:50 adam Exp $

DISTNAME=	django-classy-tags-0.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-classy-tags/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://github.com/ojii/django-classy-tags/
COMMENT=	Class based template tags for Django
LICENSE=	modified-bsd

USE_LANGUAGES=		# empty

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
