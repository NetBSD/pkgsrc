# $NetBSD: Makefile,v 1.15 2022/01/10 18:22:46 wiz Exp $

DISTNAME=	SimpleTAL-4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.owlfish.com/software/simpleTAL/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.owlfish.com/software/simpleTAL/
COMMENT=	Stand alone implementation of the Zope TAL
LICENSE=	modified-bsd

USE_LANGUAGES=	#none

PYTHON_VERSIONS_ACCEPTED=	27

do-test:
	${PYTHONBIN} ${WRKSRC}/runtests.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
