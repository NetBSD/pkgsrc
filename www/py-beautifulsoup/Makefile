# $NetBSD: Makefile,v 1.18 2019/09/02 13:20:04 adam Exp $

DISTNAME=	BeautifulSoup-3.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/B/b/:S/S/s/}
CATEGORIES=	www python
MASTER_SITES=	https://www.crummy.com/software/BeautifulSoup/download/3.x/

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	https://www.crummy.com/software/BeautifulSoup/
COMMENT=	HTML/XML Parser for Python, version 3
LICENSE=	modified-bsd

PYTHON_VERSIONS_ACCEPTED=	 27 # use py-beautifulsoup4 for python-3.x

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
