# $NetBSD: Makefile,v 1.13 2001/02/17 17:22:09 wiz Exp $

DISTNAME=	jakarta-tomcat.src
PKGNAME=	jakarta-tomcat-3.1.1
CATEGORIES=	www
MASTER_SITES=	http://jakarta.apache.org/builds/tomcat/release/v3.1.1/src/
DISTFILES=	jakarta-tomcat-3.1.1-src.tar.gz jakarta-tools.tar.gz jakarta-ant.tar.gz

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://jakarta.apache.org/
COMMENT=	the Apache Project's Java Servlet 2.2 and JSP 1.1 server

DIST_SUBDIR=	jakarta-3.1.1

USE_JAVA=	yes

WRKSRC=		${WRKDIR}/jakarta-tomcat-3.1.1-src

JAKARTA_HOME=	${PREFIX}/jakarta
MAKE_ENV+=	JAVA_HOME=${JAVA_HOME}

MESSAGE_SUBST+=	TOMCAT_HOME=${JAKARTA_HOME}

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

do-install:
	${MKDIR} ${JAKARTA_HOME}/tomcat
	cd ${WRKSRC} && ${SH} ./build.sh dist
	${CHMOD} +x ${JAKARTA_HOME}/tomcat/bin/*.sh
	${RM} ${JAKARTA_HOME}/tomcat/bin/*.bat
	${RM} ${JAKARTA_HOME}/tomcat/bin/tomcat.sh.orig

.include "../../mk/bsd.pkg.mk"
