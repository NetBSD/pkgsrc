# $NetBSD: Makefile,v 1.1 2012/12/09 20:36:40 adam Exp $

DISTNAME=	django-photologue-2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/d/django-photologue/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jdriscoll/django-photologue/
COMMENT=	Plug-in photo management application for the Django framework
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-imaging-[0-9]*:../../graphics/py-imaging
DEPENDS+=	${PYPKGPREFIX}-django-south-[0-9]*:../../www/py-django-south
DEPENDS+=	${PYPKGPREFIX}-django-tagging-[0-9]*:../../www/py-django-tagging

PKG_DESTDIR_SUPPORT=	user-destdir

EGG_NAME=		${DISTNAME:S/-/_/}
USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
