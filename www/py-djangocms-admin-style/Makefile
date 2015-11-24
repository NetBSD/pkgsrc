# $NetBSD: Makefile,v 1.6 2015/11/24 17:26:27 adam Exp $

DISTNAME=	djangocms-admin-style-1.0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/d/djangocms-admin-style/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/djangocms-admin-style/
COMMENT=	Adds pretty CSS styles for the django CMS admin interface
LICENSE=	modified-bsd

USE_LANGUAGES=		# empty

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
