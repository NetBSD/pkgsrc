# $NetBSD: Makefile,v 1.8 2004/05/23 11:41:35 recht Exp $
#

DISTNAME=	ZopeBook
PKGNAME=	zope25-zopebook-0
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Documentation/Books/ZopeBook/current/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.zope.org/Documentation/Books/ZopeBook/current/index_html
COMMENT=	Documentation for Zope-2.5

USE_BUILDLINK3=	yes
NO_BUILD=	yes

ZBDIR=	${PREFIX}/share/doc/html/ZopeBook-2.5

do-install:
	${INSTALL_DATA_DIR} ${ZBDIR}
	cd ${WRKSRC} && ${PAX} -rw . ${ZBDIR}

.include "../../mk/bsd.pkg.mk"
