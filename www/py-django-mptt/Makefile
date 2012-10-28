# $NetBSD: Makefile,v 1.3 2012/10/28 06:31:00 asau Exp $

DISTNAME=	django-mptt-0.5.4
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
