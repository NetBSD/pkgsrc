# $NetBSD: Makefile,v 1.11 2018/08/02 15:31:03 adam Exp $

DISTNAME=	beautifulsoup4-4.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	https://www.crummy.com/software/BeautifulSoup/bs4/download/${PKGVERSION_NOREV:R}/
MASTER_SITES+=	${MASTER_SITE_PYPI:=b/beautifulsoup4/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.crummy.com/software/BeautifulSoup/
COMMENT=	HTML/XML Parser for Python, version 4
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} -m unittest discover -s bs4

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
