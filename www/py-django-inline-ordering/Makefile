# $NetBSD: Makefile,v 1.4 2022/01/04 20:55:20 wiz Exp $

DISTNAME=	django-inline-ordering-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-inline-ordering/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/centralniak/django-inline-ordering
COMMENT=	Django app to ease ordering of related data
LICENSE=	modified-bsd

USE_LANGUAGES=		# empty

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
