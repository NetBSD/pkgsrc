# $NetBSD: Makefile,v 1.1.1.1 2000/01/12 22:21:34 jwise Exp $

DISTNAME=	jakarta-tomcat.src
PKGNAME=	jakarta-tomcat-3.0
CATEGORIES=	www
MASTER_SITES=	http://jakarta.apache.org/builds/tomcat/release/v3.0/src/
DISTFILES=	jakarta-tomcat.src.zip jakarta-tools.src.zip

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://jakarta.apache.org/

DEPENDS+=	jdk-*:../../lang/jdk

WRKSRC=		${WRKDIR}/jakarta-tomcat
BUILD_DEFS=	JDK_HOME JAKARTA_HOME
EXTRACT_CMD=    ${DO_NADA}

.include "../../mk/bsd.prefs.mk"

JDK_HOME?=      ${LOCALBASE}/java
JAKARTA_HOME?=	${JDK_HOME}/jakarta
MAKE_ENV+=	JAVA_HOME=${JDK_HOME}

post-extract:
.for x in ${DISTFILES}
	cd ${WRKDIR} && ${LOCALBASE}/java/bin/jar xf ${DISTDIR}/$x
.endfor

post-patch:
	${SED} -e s,@TOMCAT_HOME@,${JAKARTA_HOME}/tomcat,g \
		< ${WRKSRC}/build.xml > ${WRKSRC}/build.xml.tmp
	${MV} ${WRKSRC}/build.xml.tmp ${WRKSRC}/build.xml

do-build:
	cd ${WRKSRC} && ${SH} ./build.sh

do-install:
	${MKDIR} ${JAKARTA_HOME}/tomcat
	cd ${WRKSRC} && ${SH} ./build.sh dist
	${INSTALL_DATA} ${WRKSRC}/Tomcat+Apache-HOWTO ${JAKARTA_HOME}/tomcat
	${CHMOD} +x ${JAKARTA_HOME}/tomcat/*.sh

.include "../../mk/bsd.pkg.mk"

# This needs to be after bsd.pkg.mk 
PREFIX:=        ${JDK_HOME}
