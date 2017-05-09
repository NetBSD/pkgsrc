# $NetBSD: Makefile,v 1.9 2017/05/09 20:05:17 adam Exp $

DISTNAME=	beautifulsoup4-4.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://www.crummy.com/software/BeautifulSoup/bs4/download/${PKGVERSION_NOREV:R}/
MASTER_SITES+=	${MASTER_SITE_PYPI:=b/beautifulsoup4/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.crummy.com/software/BeautifulSoup/
COMMENT=	HTML/XML Parser for Python, version 4
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} -m unittest discover -s bs4

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
