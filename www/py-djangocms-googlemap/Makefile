# $NetBSD: Makefile,v 1.11 2023/12/07 17:51:49 adam Exp $

DISTNAME=	djangocms-googlemap-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/djangocms-googlemap/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/django-cms/djangocms-googlemap
COMMENT=	Google Maps plugin for django CMS
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-django-cms>=3.7:../../www/py-django-cms
DEPENDS+=	${PYPKGPREFIX}-django-filer>=1.7:../../www/py-django-filer
DEPENDS+=	${PYPKGPREFIX}-django-treebeard>=4.3:../../www/py-django-treebeard

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
