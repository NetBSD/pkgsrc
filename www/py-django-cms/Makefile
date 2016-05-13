# $NetBSD: Makefile,v 1.38 2016/05/13 15:41:26 adam Exp $

DISTNAME=	django-cms-3.2.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_GITHUB:=divio/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.django-cms.org/
COMMENT=	Django content management system
LICENSE=	modified-bsd

GITHUB_PROJECT=	django-cms
GITHUB_TAG=	${PKGVERSION_NOREV}

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-django-classy-tags-[0-9]*:../../www/py-django-classy-tags
DEPENDS+=	${PYPKGPREFIX}-django-mptt-[0-9]*:../../www/py-django-mptt
DEPENDS+=	${PYPKGPREFIX}-django-sekizai-[0-9]*:../../www/py-django-sekizai
DEPENDS+=	${PYPKGPREFIX}-django-reversion-[0-9]*:../../www/py-django-reversion
DEPENDS+=	${PYPKGPREFIX}-djangocms-admin-style-[0-9]*:../../www/py-djangocms-admin-style
DEPENDS+=	${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=		# empty

REPLACE_SH=	cms/static/cms/js/select2/release.sh

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
