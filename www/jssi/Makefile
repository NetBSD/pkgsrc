# $NetBSD: Makefile,v 1.1.1.1 2000/01/18 01:51:43 jwise Exp $

DISTNAME=	ApacheJSSI-1.1.2
PKGNAME=	jssi-1.1.2
CATEGORIES=	www
MASTER_SITES=	http://java.apache.org/jservssi/dist/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://java.apache.org/

# yes, this needs _exactly_ version 2.0
DEPENDS+=	jsdk-2.0:../../www/jsdk20

.include "../../mk/bsd.prefs.mk"

USE_JAVA=
USE_GMAKE=
NO_CONFIGURE=
NO_MTREE=
MAKE_ENV+=	CLASSPATH=${CLASSPATH}:${JSDK_HOME}/lib/jsdk.jar
WRKSRC=		${WRKDIR}/ApacheJSSI-1.1.2/src/java
MESSAGE=	${WRKDIR}/MESSAGE

post-build:
	${SED} -e 's,@JSDK_HOME@,${JSDK_HOME},g' \
		< ${PKGDIR}/MESSAGE > ${WRKDIR}/MESSAGE

do-install:
	${INSTALL_DATA} ${WRKSRC}/ApacheJSSI.jar ${JSDK_HOME}/lib
	${MKDIR} ${JSDK_HOME}/doc/jssi
	(cd ${WRKSRC}/../../docs ; ${GTAR} pcf - .) | \
		(cd ${JSDK_HOME}/doc/jssi ; ${GTAR} pxvf -)

.include "../../mk/bsd.pkg.mk"
JSDK_HOME=	${JAVA_HOME}/jsdk
BUILD_DEFS+=	JSDK_HOME
PREFIX:=	${JSDK_HOME}
