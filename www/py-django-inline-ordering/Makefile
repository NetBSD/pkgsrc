# $NetBSD: Makefile,v 1.1 2013/01/28 21:07:15 adam Exp $

DISTNAME=	django-inline-ordering-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/d/django-inline-ordering/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/centralniak/django-inline-ordering
COMMENT=	Django app to ease ordering of related data
LICENSE=	modified-bsd

EGG_NAME=		${DISTNAME:S/-/_/:S/-/_/}
USE_LANGUAGES=		# empty

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
