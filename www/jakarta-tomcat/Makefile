# $NetBSD: Makefile,v 1.8 2000/05/31 23:44:58 jwise Exp $

DISTNAME=	jakarta-tomcat.src
PKGNAME=	jakarta-tomcat-3.1
CATEGORIES=	www
MASTER_SITES=	http://jakarta.apache.org/builds/tomcat/release/v3.1/src/
DISTFILES=	jakarta-tomcat.tar.gz jakarta-tools.tar.gz jakarta-ant.tar.gz
DIST_SUBDIR=	jakarta-3.1

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://jakarta.apache.org/

USE_JAVA=	yes

WRKSRC=		${WRKDIR}/jakarta-tomcat

JAKARTA_HOME=	${PREFIX}/jakarta
MAKE_ENV+=	JAVA_HOME=${JAVA_HOME}

MESSAGE_FILE=	${WRKDIR}/MESSAGE

post-patch:
	${SED} -e s,@JAKARTA_HOME@,${JAKARTA_HOME},g \
		< ${WRKSRC}/build.xml > ${WRKSRC}/build.tmp
	${MV} ${WRKSRC}/build.tmp ${WRKSRC}/build.xml
	${SED} -e s,@LOCALBASE@,${LOCALBASE},g \
		< ${WRKSRC}/src/share/org/apache/tomcat/task/ApacheConfig.java \
		> ${WRKSRC}/src/share/org/apache/tomcat/task/ApacheConfig.java.tmp
	${MV} ${WRKSRC}/src/share/org/apache/tomcat/task/ApacheConfig.java.tmp \
		${WRKSRC}/src/share/org/apache/tomcat/task/ApacheConfig.java

do-build:
	cd ${WRKSRC}/../jakarta-ant && ${SH} bootstrap.sh
	cd ${WRKSRC} && ${SH} ./build.sh

post-build:
	${SED} 's,@TOMCAT_HOME@,${JAKARTA_HOME}/tomcat,g' \
		< ${PKGDIR}/MESSAGE > ${WRKDIR}/MESSAGE

do-install:
	${MKDIR} ${JAKARTA_HOME}/tomcat
	cd ${WRKSRC} && ${SH} ./build.sh dist
	${CHMOD} +x ${JAKARTA_HOME}/tomcat/bin/*.sh
	${RM} ${JAKARTA_HOME}/tomcat/bin/*.bat

.include "../../mk/bsd.pkg.mk"
