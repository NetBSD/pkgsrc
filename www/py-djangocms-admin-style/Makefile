# $NetBSD: Makefile,v 1.9 2016/05/13 15:47:06 adam Exp $

DISTNAME=	djangocms-admin-style-1.1.1
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

# remove OS X Finder leftovers
#post-extract:
#	${RM} ${WRKSRC}/djangocms_admin_style/.DS_Store
#	${RM} ${WRKSRC}/djangocms_admin_style/static/.DS_Store

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
