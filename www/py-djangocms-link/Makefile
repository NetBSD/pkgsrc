# $NetBSD: Makefile,v 1.1 2018/12/16 14:06:09 adam Exp $

DISTNAME=	djangocms-link-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/djangocms-link/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/djangocms-link
COMMENT=	Django CMS plugin that allows to add links
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-cms>-3.4.5:../../www/py-django-cms
DEPENDS+=	${PYPKGPREFIX}-djangocms-attributes-field>=0.4.0:../../www/py-djangocms-attributes-field

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
