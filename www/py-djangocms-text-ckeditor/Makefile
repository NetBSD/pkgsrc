# $NetBSD: Makefile,v 1.7 2016/03/06 14:39:23 adam Exp $

DISTNAME=	djangocms-text-ckeditor-2.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/d/djangocms-text-ckeditor/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/djangocms-text-ckeditor/
COMMENT=	Text Plugin for django-cms with CK-Editor
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-cms-[0-9]*:../../www/py-django-cms

EXTRACT_USING=		bsdtar
USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
