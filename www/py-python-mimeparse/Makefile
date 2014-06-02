# $NetBSD: Makefile,v 1.1 2014/06/02 03:19:30 rodent Exp $

DISTNAME=	python-mimeparse-0.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python www
MASTER_SITES=	https://pypi.python.org/packages/source/p/python-mimeparse/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/dbtsai/python-mimeparse
COMMENT=	Module provides basic functions for parsing mime-type names
LICENSE=	mit

USE_LANGUAGES=	# none

EGG_NAME=	${DISTNAME:S/-/_/1}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
