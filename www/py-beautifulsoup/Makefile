# $NetBSD: Makefile,v 1.10 2014/01/25 09:25:32 wiz Exp $

DISTNAME=	BeautifulSoup-3.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/B/b/:S/S/s/}
CATEGORIES=	www python
MASTER_SITES=	http://www.crummy.com/software/BeautifulSoup/download/3.x/

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://www.crummy.com/software/BeautifulSoup/
COMMENT=	HTML/XML Parser for Python, version 3
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	33 # use py-beautifulsoup4 for python-3.x

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
