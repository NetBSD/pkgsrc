# $NetBSD: Makefile,v 1.11 2008/05/26 02:13:26 joerg Exp $
#

DISTNAME=	ZopeBook
PKGNAME=	zope25-zopebook-0
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Documentation/Books/ZopeBook/current/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zope.org/Documentation/Books/ZopeBook/current/index_html
COMMENT=	Documentation for Zope-2.5

NO_BUILD=	yes

USE_TOOLS+=	pax

ZBDIR=	${PREFIX}/share/doc/html/ZopeBook-2.5

do-install:
	${INSTALL_DATA_DIR} ${ZBDIR}
	cd ${WRKSRC} && pax -rw . ${ZBDIR}

.include "../../mk/bsd.pkg.mk"
