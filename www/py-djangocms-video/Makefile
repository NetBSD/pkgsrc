# $NetBSD: Makefile,v 1.11 2023/12/07 17:49:10 adam Exp $

DISTNAME=	djangocms-video-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/djangocms-video/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/djangocms-video
COMMENT=	Django CMS plugin that allow you to publish video content
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-django-cms>=3.7:../../www/py-django-cms
DEPENDS+=	${PYPKGPREFIX}-django-filer>=1.7:../../www/py-django-filer
DEPENDS+=	${PYPKGPREFIX}-djangocms-attributes-field>=1.0:../../www/py-djangocms-attributes-field

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
