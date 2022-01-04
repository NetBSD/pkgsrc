# $NetBSD: Makefile,v 1.8 2022/01/04 20:54:51 wiz Exp $

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

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
