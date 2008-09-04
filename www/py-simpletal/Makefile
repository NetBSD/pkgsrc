# $NetBSD: Makefile,v 1.1.1.1 2008/09/04 16:53:58 epg Exp $

DISTNAME=	SimpleTAL-4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://www.owlfish.com/software/simpleTAL/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.owlfish.com/software/simpleTAL/
COMMENT=	Stand alone implementation of the Zope TAL

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

do-test:
	${PYTHONBIN} ${WRKSRC}/runtests.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
