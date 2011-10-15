# $NetBSD: Makefile,v 1.2 2011/10/15 10:54:25 obache Exp $

DISTNAME=	SimpleTAL-4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.owlfish.com/software/simpleTAL/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.owlfish.com/software/simpleTAL/
COMMENT=	Stand alone implementation of the Zope TAL
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

do-test:
	${PYTHONBIN} ${WRKSRC}/runtests.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
