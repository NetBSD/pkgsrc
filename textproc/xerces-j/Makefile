# $NetBSD: Makefile,v 1.22 2004/06/28 17:28:57 abs Exp $
#
# Note: we currently use the pre-built (-bin) distribution of Xerces-J,
# because although Xerces runs fine under JDK 1.1, JDK 1.2 or greater is
# required to build it.

DISTNAME=	Xerces-J-bin.1.2.0
PKGNAME=	xerces-j-1.2.0
CATEGORIES=	textproc www
MASTER_SITES=	http://xml.apache.org/dist/xerces-j/

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://xml.apache.org/xerces-j/
COMMENT=	The Apache Project's validating XML parser with DOM and SAX support

WRKSRC=		${WRKDIR}/xerces-1_2_0
USE_JAVA=	run
USE_BUILDLINK3= YES
NO_CONFIGURE=
NO_BUILD=

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/xerces.jar ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/xerces
	cd ${WRKSRC}/docs && ${PAX} -rw -pp . ${PREFIX}/share/doc/java/xerces
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/java/xerces
	${INSTALL_DATA} ${WRKSRC}/xercesSamples.jar ${PREFIX}/share/examples/java/xerces
	cd ${WRKSRC}/data && ${PAX} -rw -pp . ${PREFIX}/share/examples/java/xerces

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
