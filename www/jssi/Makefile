# $NetBSD: Makefile,v 1.26 2005/12/26 23:39:34 schmonz Exp $

DISTNAME=	ApacheJSSI-1.1.2
PKGNAME=	jssi-1.1.2
CATEGORIES=	www java
MASTER_SITES=	http://java.apache.org/jservssi/dist/

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://java.apache.org/
COMMENT=	Java Server-Side Include engine as a JSDK-2.0 servlet

PKG_FAIL_REASON+=	"Broken on NetBSD/i386 3.0 in pkgsrc-2005Q4"
PKG_FAIL_REASON+=	"Will be removed in pkgsrc-2006Q1 unless fixed"

# yes, this needs _exactly_ version 2.0
DEPENDS+=	jsdk-2.0:../../www/jsdk20

WRKSRC=		${WRKDIR}/ApacheJSSI-1.1.2/src/java

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=	gmake
NO_CONFIGURE=	yes
MAKE_ENV+=	CLASSPATH=${CLASSPATH:Q}

post-build:
	(cd ${WRKSRC}/../../docs && ${SETENV} ${SCRIPTS_ENV} ${SH} generate_javadoc)

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/ApacheJSSI.jar ${PREFIX}/lib/java/ApacheJSSI.jar
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/jssi
	${RM} -f ${WRKSRC}/../../docs/*.orig
	cd ${WRKSRC}/../../docs && ${PAX} -rw -pp . ${PREFIX}/share/doc/java/jssi

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"

# This must be after bsd.pkg.mk is brought in
CLASSPATH:=${CLASSPATH}:${PREFIX}/lib/java/jsdk.jar:${PKG_JAVA_HOME}/lib/classes.zip:${PKG_JAVA_HOME}/lib/tools.jar
