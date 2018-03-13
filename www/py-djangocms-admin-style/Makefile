# $NetBSD: Makefile,v 1.13 2018/03/13 09:43:33 adam Exp $

DISTNAME=	djangocms-admin-style-1.2.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/djangocms-admin-style/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/djangocms-admin-style
COMMENT=	Adds pretty CSS styles for the django CMS admin interface
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

USE_LANGUAGES=	# none

post-extract:
	${RM} ${WRKSRC}/djangocms_admin_style/.DS_Store

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
