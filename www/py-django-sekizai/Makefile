# $NetBSD: Makefile,v 1.2 2012/03/10 19:49:02 wiz Exp $

DISTNAME=	django-sekizai-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/d/django-sekizai/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/ojii/django-sekizai
COMMENT=	Django Template Blocks with extra functionality
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_INCOMPATIBLE=	24

USE_LANGUAGES=		# empty
EGG_NAME=		${DISTNAME:S/-/_/}

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
