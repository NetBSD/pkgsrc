# $NetBSD: Makefile,v 1.1 2014/06/08 22:03:54 rodent Exp $

DISTNAME=	boto-2.29.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python www
MASTER_SITES=	https://pypi.python.org/packages/source/b/boto/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/boto/boto/
COMMENT=	Amazon Web Services Library
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 34
REPLACE_PYTHON+=		boto/pyami/launch_ami.py boto/services/bs.py
REPLACE_PYTHON+=		boto/services/result.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
