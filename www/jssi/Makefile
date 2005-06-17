# $NetBSD: Makefile,v 1.21 2005/06/17 03:50:40 jlam Exp $

DISTNAME=	ApacheJSSI-1.1.2
PKGNAME=	jssi-1.1.2
CATEGORIES=	www java
MASTER_SITES=	http://java.apache.org/jservssi/dist/

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://java.apache.org/
COMMENT=	Java Server-Side Include engine as a JSDK-2.0 servlet

# yes, this needs _exactly_ version 2.0
DEPENDS+=	jsdk-2.0:../../www/jsdk20

WRKSRC=		${WRKDIR}/ApacheJSSI-1.1.2/src/java

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=		gmake
NO_CONFIGURE=
MAKE_ENV+=	CLASSPATH=${CLASSPATH}

post-build:
	(cd ${WRKSRC}/../../docs && ${SETENV} ${SCRIPTS_ENV} ${SH} generate_javadoc)

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/ApacheJSSI.jar ${PREFIX}/lib/java/ApacheJSSI.jar
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/jssi
	cd ${WRKSRC}/../../docs && ${PAX} -rw -pp . ${PREFIX}/share/doc/java/jssi

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"

# This must be after bsd.pkg.mk is brought in
CLASSPATH:=${CLASSPATH}:${PREFIX}/lib/java/jsdk.jar:${PKG_JAVA_HOME}/lib/classes.zip:${PKG_JAVA_HOME}/lib/tools.jar
