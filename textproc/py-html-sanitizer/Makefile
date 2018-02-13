# $NetBSD: Makefile,v 1.1 2018/02/13 21:00:03 joerg Exp $

DISTNAME=	html-sanitizer-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/html-sanitizer/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://github.com/matthiask/html-sanitizer/
COMMENT=	White-list based HTML sanitizer
LICENSE=	modified-bsd

USE_LANGUAGES=		# none

DEPENDS+=	${PYPKGPREFIX}-lxml>3:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
