# $NetBSD: Makefile,v 1.16 2019/01/29 08:45:43 adam Exp $

DISTNAME=	djangocms-admin-style-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/djangocms-admin-style/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/djangocms-admin-style
COMMENT=	Adds pretty CSS styles for the django CMS admin interface
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
