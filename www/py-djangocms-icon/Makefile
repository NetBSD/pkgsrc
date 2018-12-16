# $NetBSD: Makefile,v 1.1 2018/12/16 14:05:36 adam Exp $

DISTNAME=	djangocms-icon-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/djangocms-icon/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/djangocms-icon
COMMENT=	Django CMS plugin that inserts an icon (font or svg)
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-cms>-3.4.5:../../www/py-django-cms
DEPENDS+=	${PYPKGPREFIX}-djangocms-attributes-field>=0.4.0:../../www/py-djangocms-attributes-field

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
