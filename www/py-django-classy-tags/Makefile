# $NetBSD: Makefile,v 1.5 2012/04/08 19:09:15 wiz Exp $

DISTNAME=	django-classy-tags-0.3.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/d/django-classy-tags/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://github.com/ojii/django-classy-tags/
COMMENT=	Class based template tags for Django
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

EGG_NAME=		${DISTNAME:S/-/_/:S/-/_/}
USE_LANGUAGES=		# empty

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
