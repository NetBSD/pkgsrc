# $NetBSD: Makefile,v 1.14 2018/03/24 08:25:30 adam Exp $

DISTNAME=	scgi-1.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://python.ca/scgi/releases/

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://python.ca/scgi/
COMMENT=	Simple Common Gateway Interface
LICENSE=	cnri-license

DEPENDS+=	${PYPKGPREFIX}-quixote-[0-9]*:../../devel/py-quixote

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-quixote

CFLAGS.SunOS+=	-D_XOPEN_SOURCE -D_XOPEN_SOURCE_EXTENDED=1

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
