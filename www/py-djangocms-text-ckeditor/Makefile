# $NetBSD: Makefile,v 1.6 2015/12/10 12:34:43 adam Exp $

DISTNAME=	djangocms-text-ckeditor-2.8.0
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

# XXX 2.8.0 has some empty files
post-extract:
	find ${WRKSRC}/djangocms_text_ckeditor/static/djangocms_text_ckeditor/ckeditor/samples -empty -exec rm {} \;

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
