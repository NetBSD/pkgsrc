# $NetBSD: Makefile,v 1.2 2023/05/04 11:39:23 wiz Exp $

DISTNAME=	xmldiff-2.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xmldiff/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Shoobx/xmldiff
COMMENT=	Creates diffs of XML files
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin; \
	${MV} xmldiff xmldiff-${PYVERSSUFFIX}; \
	${MV} xmlpatch xmlpatch-${PYVERSSUFFIX}; \
	${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
