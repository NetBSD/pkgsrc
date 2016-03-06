# $NetBSD: Makefile,v 1.8 2016/03/06 14:22:37 adam Exp $

DISTNAME=	djangocms-admin-style-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/d/djangocms-admin-style/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/djangocms-admin-style/
COMMENT=	Adds pretty CSS styles for the django CMS admin interface
LICENSE=	modified-bsd

USE_LANGUAGES=		# empty

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

# remove OS X Finder leftovers
post-extract:
	${RM} ${WRKSRC}/djangocms_admin_style/.DS_Store
	${RM} ${WRKSRC}/djangocms_admin_style/static/.DS_Store

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
