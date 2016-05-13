# $NetBSD: Makefile,v 1.8 2016/05/13 15:44:16 adam Exp $

DISTNAME=	djangocms-text-ckeditor-2.9.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_GITHUB:=divio/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/djangocms-text-ckeditor/
COMMENT=	Text Plugin for django-cms with CK-Editor
LICENSE=	modified-bsd

GITHUB_PROJECT=	djangocms-text-ckeditor
GITHUB_TAG=	${PKGVERSION_NOREV}

DEPENDS+=	${PYPKGPREFIX}-django-cms-[0-9]*:../../www/py-django-cms

EXTRACT_USING=		bsdtar
USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
