# $NetBSD: Makefile,v 1.33 2008/05/26 02:13:25 joerg Exp $

DISTNAME=	ApacheJSSI-1.1.2
PKGNAME=	jssi-1.1.2
PKGREVISION=	1
CATEGORIES=	www java
MASTER_SITES=	http://java.apache.org/jservssi/dist/

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://java.apache.org/
COMMENT=	Java Server-Side Include engine as a JSDK-2.0 servlet

BROKEN=		this package is unmaintained and supplanted by newer tomcat releases.  if you use this, speak now.
BROKEN_IN=	pkgsrc-2006Q1 pkgsrc-2006Q4

# yes, this needs _exactly_ version 2.0
DEPENDS+=	jsdk-2.0nb1:../../www/jsdk20

BUILD_DIRS=	src/java

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=	gmake pax
NO_CONFIGURE=	yes
MAKE_ENV+=	CLASSPATH=${CLASSPATH:Q}

post-build:
	cd ${WRKSRC}/docs && ${SETENV} ${SCRIPTS_ENV} ${SH} ./generate_javadoc

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/src/java/ApacheJSSI.jar ${PREFIX}/lib/java/ApacheJSSI.jar
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/jssi
	${RM} -f ${WRKSRC}/docs/*.orig
	cd ${WRKSRC}/docs && pax -rw -pp . ${PREFIX}/share/doc/java/jssi

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"

# This must be after bsd.pkg.mk is brought in
CLASSPATH:=${CLASSPATH}:${PREFIX}/lib/java/jsdk.jar:${PKG_JAVA_HOME}/lib/classes.zip:${PKG_JAVA_HOME}/lib/tools.jar
