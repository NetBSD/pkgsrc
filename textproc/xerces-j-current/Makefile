# $NetBSD: Makefile,v 1.1.1.1 2000/05/31 21:40:07 jwise Exp $
#
# Note: we currently use the pre-built (-bin) distribution of Xerces-J,
# because although Xerces runs fine under JDK 1.1, JDK 1.2 or greater is
# required to build it.

DISTNAME=	Xerces-J-bin.1.1.0
PKGNAME=	xerces-j-current-1.1.0
CATEGORIES=	textproc www
MASTER_SITES=	http://xml.apache.org/dist/xerces-j/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://xml.apache.org/xerces-j/

CONFLICTS=	xerces-j-[0-9]*

NO_PATCH=
NO_CONFIGURE=
NO_BUILD=

USE_JAVA=	yes

WRKSRC=		${WRKDIR}/xerces-1_1_0

do-install:
	${MKDIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/xerces.jar ${PREFIX}/lib/java
	${MKDIR} ${PREFIX}/share/doc/java/xerces
	cd ${WRKSRC}/docs ; ${GTAR} pcf - . | ( cd ${PREFIX}/share/doc/java/xerces ; ${GTAR} pvxf - )
	${MKDIR} ${PREFIX}/share/examples/java/xerces
	${INSTALL_DATA} ${WRKSRC}/xercesSamples.jar ${PREFIX}/share/examples/java/xerces
	cd ${WRKSRC}/data ; ${GTAR} pcf - . | ( cd ${PREFIX}/share/examples/java/xerces ; ${GTAR} pvxf - )

.include "../../mk/bsd.pkg.mk"
