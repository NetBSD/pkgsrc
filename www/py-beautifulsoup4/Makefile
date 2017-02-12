# $NetBSD: Makefile,v 1.8 2017/02/12 04:01:39 wen Exp $

DISTNAME=	beautifulsoup4-4.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://www.crummy.com/software/BeautifulSoup/bs4/download/4.5/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.crummy.com/software/BeautifulSoup/
COMMENT=	HTML/XML Parser for Python, version 4
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

do-test:
	cd ${WRKSRC} &&  ${PYTHONBIN} -m unittest discover -s bs4

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
