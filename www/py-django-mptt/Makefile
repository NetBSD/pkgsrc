# $NetBSD: Makefile,v 1.12 2016/06/08 17:43:45 wiz Exp $

DISTNAME=	django-mptt-0.8.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-mptt/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://github.com/django-mptt/django-mptt
COMMENT=	Utilities for implementing Modified Preorder Tree Traversal
LICENSE=	mit

USE_LANGUAGES=		# empty

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

post-extract:
	${RM} -f -r ${WRKSRC}/tests/__pycache__ ${WRKSRC}/tests/*.pyc
	${RM} -f -r ${WRKSRC}/tests/myapp/__pycache__ ${WRKSRC}/tests/myapp/*.pyc

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
