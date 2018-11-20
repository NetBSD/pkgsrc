# $NetBSD: Makefile,v 1.9 2018/11/20 18:40:17 adam Exp $

DISTNAME=	djangocms-text-ckeditor-3.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/djangocms-text-ckeditor/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/djangocms-text-ckeditor
COMMENT=	Text Plugin for django-cms with CK-Editor
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-django-cms>=3.3.0:../../www/py-django-cms
DEPENDS+=	${PYPKGPREFIX}-html5lib>=0.999999999:../../textproc/py-html5lib

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
