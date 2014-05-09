# $NetBSD: Makefile,v 1.11 2014/05/09 07:37:24 wiz Exp $

DISTNAME=	BeautifulSoup-3.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/B/b/:S/S/s/}
CATEGORIES=	www python
MASTER_SITES=	http://www.crummy.com/software/BeautifulSoup/download/3.x/

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://www.crummy.com/software/BeautifulSoup/
COMMENT=	HTML/XML Parser for Python, version 3
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # use py-beautifulsoup4 for python-3.x

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
