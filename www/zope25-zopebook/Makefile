# $NetBSD: Makefile,v 1.9 2005/04/11 21:48:03 tv Exp $
#

DISTNAME=	ZopeBook
PKGNAME=	zope25-zopebook-0
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Documentation/Books/ZopeBook/current/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.zope.org/Documentation/Books/ZopeBook/current/index_html
COMMENT=	Documentation for Zope-2.5

NO_BUILD=	yes

ZBDIR=	${PREFIX}/share/doc/html/ZopeBook-2.5

do-install:
	${INSTALL_DATA_DIR} ${ZBDIR}
	cd ${WRKSRC} && ${PAX} -rw . ${ZBDIR}

.include "../../mk/bsd.pkg.mk"
