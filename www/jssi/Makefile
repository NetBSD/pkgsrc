# $NetBSD: Makefile,v 1.9 2001/11/14 14:47:57 agc Exp $

DISTNAME=	ApacheJSSI-1.1.2
PKGNAME=	jssi-1.1.2
CATEGORIES=	www
MASTER_SITES=	http://java.apache.org/jservssi/dist/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://java.apache.org/
COMMENT=	Java Server-Side Include engine as a JSDK-2.0 servlet

# yes, this needs _exactly_ version 2.0
DEPENDS+=	jsdk-2.0:../../www/jsdk20

.include "../../mk/bsd.prefs.mk"

USE_JAVA=
USE_GMAKE=
NO_CONFIGURE=
WRKSRC=		${WRKDIR}/ApacheJSSI-1.1.2/src/java
MAKE_ENV+=	CLASSPATH=${CLASSPATH}

post-build:
	(cd ${WRKSRC}/../../docs && CLASSPATH=${CLASSPATH} ${SH} generate_javadoc)

do-install:
	${INSTALL_DATA} ${WRKSRC}/ApacheJSSI.jar ${PREFIX}/lib/java/ApacheJSSI.jar
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/jssi
	cd ${WRKSRC}/../../docs && ${PAX} -rwpe . ${PREFIX}/share/doc/java/jssi
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/java/jssi

.include "../../mk/bsd.pkg.mk"

# This must be after bsd.pkg.mk is brought in
CLASSPATH:=${CLASSPATH}:${PREFIX}/lib/java/jsdk.jar:${JAVA_HOME}/lib/classes.zip:${JAVA_HOME}/lib/tools.jar
