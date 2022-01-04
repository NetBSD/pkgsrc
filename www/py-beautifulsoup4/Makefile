# $NetBSD: Makefile,v 1.24 2022/01/04 20:55:16 wiz Exp $

DISTNAME=	beautifulsoup4-4.9.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	https://www.crummy.com/software/BeautifulSoup/bs4/download/${PKGVERSION_NOREV:R}/
MASTER_SITES+=	${MASTER_SITE_PYPI:=b/beautifulsoup4/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.crummy.com/software/BeautifulSoup/
COMMENT=	HTML/XML Parser for Python, version 4
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-soupsieve>=1.2:../../www/py-soupsieve

USE_LANGUAGES=	# none

pre-build:
	cd ${WRKSRC} && 2to3-${PYVERSSUFFIX} -w --no-diffs bs4

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} -m unittest discover -s bs4

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
