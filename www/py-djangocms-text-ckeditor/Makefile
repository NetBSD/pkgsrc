# $NetBSD: Makefile,v 1.16 2023/10/10 17:01:31 adam Exp $

DISTNAME=	djangocms-text-ckeditor-5.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/djangocms-text-ckeditor/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/djangocms-text-ckeditor
COMMENT=	Text Plugin for Django CMS with CK-Editor
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-django-cms>=3.6:../../www/py-django-cms
DEPENDS+=	${PYPKGPREFIX}-html5lib>=1.0:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
