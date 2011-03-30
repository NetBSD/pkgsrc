# $NetBSD: Makefile,v 1.3 2011/03/30 12:38:00 joerg Exp $

DISTNAME=	django-classy-tags-0.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/d/django-classy-tags/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://github.com/ojii/django-classy-tags/
COMMENT=	Class based template tags for Django
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED=	27 26 25

EGG_NAME=		${DISTNAME:S/-/_/:S/-/_/}
USE_LANGUAGES=		# empty

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
