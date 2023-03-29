# $NetBSD: Makefile,v 1.12 2023/03/29 09:34:15 wiz Exp $

DISTNAME=	h11-0.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/h11/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-hyper/h11
COMMENT=	Pure-Python, bring-your-own-I/O implementation of HTTP/1.1
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 308
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>0:../../devel/py-typing-extensions
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
