# $NetBSD: Makefile,v 1.2 2018/04/05 13:11:32 joerg Exp $

DISTNAME=	html-sanitizer-1.4.0
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
