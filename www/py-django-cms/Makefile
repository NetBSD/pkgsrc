# $NetBSD: Makefile,v 1.36 2016/03/25 21:04:04 joerg Exp $

DISTNAME=	django-cms-3.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/d/django-cms/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.django-cms.org/
COMMENT=	Django content management system
LICENSE=	modified-bsd

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
