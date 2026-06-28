# $NetBSD: Makefile,v 1.14 2026/06/28 15:41:45 wiz Exp $

DISTNAME=	djangocms-googlemap-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/djangocms-googlemap/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/django-cms/djangocms-googlemap
COMMENT=	Google Maps plugin for django CMS
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-django-cms>=3.7:../../www/py-django-cms
DEPENDS+=	${PYPKGPREFIX}-django-filer>=1.7:../../www/py-django-filer
DEPENDS+=	${PYPKGPREFIX}-django-treebeard>=4.3:../../www/py-django-treebeard

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
