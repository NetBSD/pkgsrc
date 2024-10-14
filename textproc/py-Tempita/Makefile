# $NetBSD: Makefile,v 1.9 2024/10/14 07:13:41 wiz Exp $

DISTNAME=		Tempita-0.5.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		textproc python
MASTER_SITES=		${MASTER_SITE_PYPI:=T/Tempita/}

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://pythonpaste.org/tempita/
COMMENT=		Small Python templating language
LICENSE=		mit

post-extract:
	cd ${WRKSRC} && 2to3-${PYVERSSUFFIX} -w --no-diffs tempita

PYTHON_VERSIONS_INCOMPATIBLE=	313 # 2to3

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
