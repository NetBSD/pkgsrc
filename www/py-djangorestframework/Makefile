# $NetBSD: Makefile,v 1.5 2014/05/09 07:37:25 wiz Exp $

DISTNAME=	djangorestframework-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/d/djangorestframework/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://django-rest-framework.org/
COMMENT=	Lightweight REST framework for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

EGG_NAME=		${DISTNAME}
USE_LANGUAGES=		# empty
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.2.3

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
