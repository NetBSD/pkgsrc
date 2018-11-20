# $NetBSD: Makefile,v 1.5 2018/11/20 18:44:03 adam Exp $

DISTNAME=	djangocms-googlemap-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/djangocms-googlemap/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/djangocms-googlemap
COMMENT=	Google Maps plugin for django CMS
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-cms>=3.4.5:../../www/py-django-cms
DEPENDS+=	${PYPKGPREFIX}-django-filer-[0-9]*:../../www/py-django-filer

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
