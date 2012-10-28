# $NetBSD: Makefile,v 1.4 2012/10/28 06:31:02 asau Exp $

DISTNAME=	SimpleTAL-4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.owlfish.com/software/simpleTAL/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.owlfish.com/software/simpleTAL/
COMMENT=	Stand alone implementation of the Zope TAL
LICENSE=	modified-bsd

USE_LANGUAGES=	#none

do-test:
	${PYTHONBIN} ${WRKSRC}/runtests.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
