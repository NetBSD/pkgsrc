# $NetBSD: Makefile,v 1.16 2018/07/03 05:03:39 adam Exp $

DISTNAME=	BeautifulSoup-3.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/B/b/:S/S/s/}
CATEGORIES=	www python
MASTER_SITES=	https://www.crummy.com/software/BeautifulSoup/download/3.x/

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	https://www.crummy.com/software/BeautifulSoup/
COMMENT=	HTML/XML Parser for Python, version 3
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # use py-beautifulsoup4 for python-3.x

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
