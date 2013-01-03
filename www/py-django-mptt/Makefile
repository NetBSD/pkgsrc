# $NetBSD: Makefile,v 1.4 2013/01/03 09:56:14 adam Exp $

DISTNAME=	django-mptt-0.5.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/d/django-mptt/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://github.com/django-mptt/django-mptt
COMMENT=	Utilities for implementing Modified Preorder Tree Traversal
LICENSE=	mit

USE_LANGUAGES=		# empty
PYDISTUTILSPKG=		yes

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
