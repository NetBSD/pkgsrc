# $NetBSD: Makefile,v 1.12 2016/11/06 14:48:35 adam Exp $

DISTNAME=	djangocms-admin-style-1.2.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_GITHUB:=divio/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/djangocms-admin-style/
COMMENT=	Adds pretty CSS styles for the django CMS admin interface
LICENSE=	modified-bsd

GITHUB_PROJECT=	djangocms-admin-style
GITHUB_TAG=	${PKGVERSION_NOREV}

USE_LANGUAGES=		# empty

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
