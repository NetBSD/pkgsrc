# $NetBSD: Makefile,v 1.2 2026/11/15 22:43:08 wiz Exp $

DISTNAME=	pyshacl-0.40.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyshacl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/RDFLib/pySHACL
COMMENT=	Python SHACL Validator
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry>=0:../../devel/py-poetry
DEPENDS+=	${PYPKGPREFIX}-rdflib>=7.3.0:../../textproc/py-rdflib
DEPENDS+=	${PYPKGPREFIX}-owlrl>=7.6.2:../../textproc/py-owlrl
DEPENDS+=	${PYPKGPREFIX}-prettytable>=3.7.0:../../textproc/py-prettytable
DEPENDS+=	${PYPKGPREFIX}-packaging>=21.3:../../devel/py-packaging
# optional, unpackaged: duktape2

USE_LANGUAGES=	# none

# as of 0.40.2
# 8 failed, 390 passed, 12 skipped, 367117 warning
# due to missing duktape2

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
