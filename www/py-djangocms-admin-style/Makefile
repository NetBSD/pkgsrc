# $NetBSD: Makefile,v 1.15 2018/11/20 17:08:28 adam Exp $

DISTNAME=	djangocms-admin-style-1.2.9
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
	${RM} ${WRKSRC}/djangocms_admin_style/tests/integration/.DS_Store
	${RM} ${WRKSRC}/djangocms_admin_style/static/.DS_Store
	${RM} ${WRKSRC}/djangocms_admin_style/static/djangocms_admin_style/.DS_Store
	${RM} ${WRKSRC}/djangocms_admin_style/static/djangocms_admin_style/css/.DS_Store
	${RM} ${WRKSRC}/djangocms_admin_style/static/djangocms_admin_style/js/.DS_Store
	${RM} ${WRKSRC}/djangocms_admin_style/static/djangocms_admin_style/js/dist/.DS_Store
	${RM} ${WRKSRC}/djangocms_admin_style/static/djangocms_admin_style/js/libs/.DS_Store
	${RM} ${WRKSRC}/djangocms_admin_style/static/djangocms_admin_style/fonts/.DS_Store
	${RM} ${WRKSRC}/djangocms_admin_style/static/djangocms_admin_style/fonts/src/.DS_Store
	${RM} ${WRKSRC}/djangocms_admin_style/static/cms/.DS_Store
	${RM} ${WRKSRC}/djangocms_admin_style/sass/.DS_Store

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
