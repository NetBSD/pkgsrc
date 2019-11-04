# $NetBSD: Makefile,v 1.13 2019/11/04 22:10:13 rillig Exp $

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

PYTHON_VERSIONS_ACCEPTED=	27

do-test:
	${PYTHONBIN} ${WRKSRC}/runtests.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
