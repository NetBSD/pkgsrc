# $NetBSD: Makefile,v 1.8 2014/05/10 15:46:52 joerg Exp $

DISTNAME=	0.999
PKGNAME=	${PYPKGPREFIX}-html5lib-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc www python
MASTER_SITES=	https://github.com/html5lib/html5lib-python/archive/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://github.com/html5lib/html5lib-python
COMMENT=	HTML5 parser and tokenizer
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

DIST_SUBDIR=	py-html5lib
WRKSRC=		${WRKDIR}/html5lib-python-${DISTNAME}
EGG_NAME=	html5lib-${DISTNAME}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
