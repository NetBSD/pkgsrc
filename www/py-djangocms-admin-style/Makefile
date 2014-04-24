# $NetBSD: Makefile,v 1.1 2014/04/24 19:52:08 adam Exp $

DISTNAME=	djangocms-admin-style-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/d/djangocms-admin-style/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/djangocms-admin-style/
COMMENT=	Adds pretty CSS styles for the django CMS admin interface
LICENSE=	modified-bsd

EGG_NAME=		${DISTNAME:S/-/_/:S/-/_/}
USE_LANGUAGES=		# empty

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
