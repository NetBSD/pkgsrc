# $NetBSD: Makefile,v 1.21 2025/07/07 05:58:07 wiz Exp $

DISTNAME=	djangocms_text_ckeditor-5.1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/djangocms-text-ckeditor/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/django-cms/djangocms-text-ckeditor
COMMENT=	Text Plugin for Django CMS with CK-Editor
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-django-cms>=3.6:../../www/py-django-cms
DEPENDS+=	${PYPKGPREFIX}-html5lib>=1.0:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
