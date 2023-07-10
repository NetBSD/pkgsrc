# $NetBSD: Makefile,v 1.3 2023/07/10 20:50:06 adam Exp $

DISTNAME=	xmldiff-2.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xmldiff/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Shoobx/xmldiff
COMMENT=	Creates diffs of XML files
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-lxml>=3.1.0:../../textproc/py-lxml

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
.for bin in xmldiff xmlpatch
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
