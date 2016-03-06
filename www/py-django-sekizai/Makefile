# $NetBSD: Makefile,v 1.10 2016/03/06 14:24:18 adam Exp $

DISTNAME=	django-sekizai-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/d/django-sekizai/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/ojii/django-sekizai
COMMENT=	Django Template Blocks with extra functionality
LICENSE=	modified-bsd

USE_LANGUAGES=		# empty

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
