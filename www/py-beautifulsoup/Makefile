# $NetBSD: Makefile,v 1.22 2022/01/04 20:55:16 wiz Exp $

DISTNAME=	BeautifulSoup-3.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/B/b/:S/S/s/}
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
