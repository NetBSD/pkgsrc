# $NetBSD: Makefile,v 1.11 2016/03/14 19:04:52 adam Exp $

DISTNAME=	django-mptt-0.8.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/d/django-mptt/

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
