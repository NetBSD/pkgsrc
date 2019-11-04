# $NetBSD: Makefile,v 1.18 2019/11/04 22:10:13 rillig Exp $

DISTNAME=	scgi-1.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://python.ca/scgi/releases/

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://python.ca/scgi/
COMMENT=	Simple Common Gateway Interface
LICENSE=	cnri-license

DEPENDS+=	${PYPKGPREFIX}-quixote-[0-9]*:../../devel/py-quixote

PYTHON_VERSIONS_ACCEPTED=	27 # py-quixote

CFLAGS.SunOS+=	-D_XOPEN_SOURCE -D_XOPEN_SOURCE_EXTENDED=1

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
