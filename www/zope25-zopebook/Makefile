# $NetBSD: Makefile,v 1.1.1.1 2002/12/03 19:48:53 drochner Exp $
#

DISTNAME=	ZopeBook
PKGNAME=	zope25-zopebook
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Documentation/Books/ZopeBook/current/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.zope.org/Documentation/Books/ZopeBook/current/index_html
COMMENT=	Documentation for Zope-2.5

USE_BUILDLINK2=	YES
NO_BUILD=	yes

ZBDIR=	${PREFIX}/share/doc/html/ZopeBook-2.5

do-install:
	${INSTALL_DATA_DIR} ${ZBDIR}
	(cd ${WRKSRC}; ${PAX} -rw . ${ZBDIR})

.include "../../mk/bsd.pkg.mk"
