# $NetBSD: Makefile,v 1.20 2022/01/10 22:46:42 wiz Exp $

DISTNAME=	scgi-1.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://python.ca/scgi/releases/

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	https://python.ca/scgi/
COMMENT=	Simple Common Gateway Interface
LICENSE=	cnri-license

DEPENDS+=	${PYPKGPREFIX}-quixote-[0-9]*:../../devel/py-quixote

PYTHON_VERSIONS_ACCEPTED=	27 # py-quixote

CFLAGS.SunOS+=	-D_XOPEN_SOURCE -D_XOPEN_SOURCE_EXTENDED=1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
