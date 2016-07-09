# $NetBSD: Makefile,v 1.9 2016/07/09 13:04:14 wiz Exp $

DISTNAME=	djangorestframework-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/djangorestframework/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://django-rest-framework.org/
COMMENT=	Lightweight REST framework for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

USE_LANGUAGES=		# empty
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported as of 0.2.3

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
