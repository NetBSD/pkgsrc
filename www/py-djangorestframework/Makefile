# $NetBSD: Makefile,v 1.2 2012/04/08 19:09:16 wiz Exp $

DISTNAME=	djangorestframework-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/d/djangorestframework/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://django-rest-framework.org/
COMMENT=	Lightweight REST framework for Django
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

EGG_NAME=		${DISTNAME}
USE_LANGUAGES=		# empty

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
