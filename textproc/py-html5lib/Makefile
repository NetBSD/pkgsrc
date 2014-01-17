# $NetBSD: Makefile,v 1.7 2014/01/17 23:32:02 wiz Exp $

DISTNAME=	0.999
PKGNAME=	${PYPKGPREFIX}-html5lib-${DISTNAME}
CATEGORIES=	textproc www python
MASTER_SITES=	https://github.com/html5lib/html5lib-python/archive/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://github.com/html5lib/html5lib-python
COMMENT=	HTML5 parser and tokenizer
LICENSE=	mit

DIST_SUBDIR=	py-html5lib
WRKSRC=		${WRKDIR}/html5lib-python-${DISTNAME}
EGG_NAME=	html5lib-${DISTNAME}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
