# $NetBSD: Makefile,v 1.11 2001/11/14 14:47:56 agc Exp $
#
# Note: we currently use the pre-built (-bin) distribution of Xerces-J,
# because although Xerces runs fine under JDK 1.1, JDK 1.2 or greater is
# required to build it.

DISTNAME=	Xerces-J-bin.1.2.0
PKGNAME=	xerces-j-1.2.0
CATEGORIES=	textproc www
MASTER_SITES=	http://xml.apache.org/dist/xerces-j/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://xml.apache.org/xerces-j/
COMMENT=	the Apache Project's validating XML parser with DOM and SAX support

NO_PATCH=
NO_CONFIGURE=
NO_BUILD=

USE_JAVA=	yes

WRKSRC=		${WRKDIR}/xerces-1_2_0

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/xerces.jar ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/xerces
	cd ${WRKSRC}/docs && ${PAX} -rwpe . ${PREFIX}/share/doc/java/xerces
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/java/xerces
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/java/xerces
	${INSTALL_DATA} ${WRKSRC}/xercesSamples.jar ${PREFIX}/share/examples/java/xerces
	cd ${WRKSRC}/data && ${PAX} -rwpe . ${PREFIX}/share/examples/java/xerces
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/examples/java/xerces

.include "../../mk/bsd.pkg.mk"
