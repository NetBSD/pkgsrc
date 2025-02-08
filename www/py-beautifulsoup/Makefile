# $NetBSD: Makefile,v 1.23 2025/02/08 23:53:38 rillig Exp $

DISTNAME=	BeautifulSoup-3.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	https://www.crummy.com/software/BeautifulSoup/download/3.x/
MASTER_SITES+=	${MASTER_SITE_PYPI:=b/beautifulsoup/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.crummy.com/software/BeautifulSoup/
COMMENT=	HTML/XML Parser for Python, version 3
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27 # use py-beautifulsoup4 for python-3.x

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
