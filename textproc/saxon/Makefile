# $NetBSD: Makefile,v 1.4 2002/07/29 22:23:28 jlam Exp $
#

DISTNAME=	saxon
PKGNAME=	saxon-6.0.2
CATEGORIES=	textproc www
MASTER_SITES=	${HOMEPAGE}saxon6.0.2/
EXTRACT_SUFX=	.zip

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://users.iclway.co.uk/mhkay/saxon/
COMMENT=	Michael H. Kay's Java XSLT processor

DIST_SUBDIR=	${PKGNAME}
USE_JAVA=	run
NO_PATCH=
NO_CONFIGURE=
NO_BUILD=
WRKSRC=		${WRKDIR}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/saxon.jar ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java
	(cd ${WRKSRC} && ${PAX} -r -w -s '/^doc/saxon/' doc ${PREFIX}/share/doc/java)
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/java/saxon
	(cd ${WRKSRC} && ${PAX} -r -w -s '/^samples/saxon/' samples ${PREFIX}/share/examples/java)

.include "../../mk/bsd.pkg.mk"
