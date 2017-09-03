# $NetBSD: Makefile,v 1.10 2017/09/03 08:53:17 wiz Exp $

DISTNAME=	beautifulsoup4-4.6.0
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
