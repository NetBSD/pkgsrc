# $NetBSD: Makefile,v 1.6 2000/01/16 21:41:08 jwise Exp $

DISTNAME=	jakarta-tomcat.src
PKGNAME=	jakarta-tomcat-3.0
CATEGORIES=	www
MASTER_SITES=	http://jakarta.apache.org/builds/tomcat/release/v3.0/src/
DISTFILES=	jakarta-tomcat.src.zip jakarta-tools.src.zip

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://jakarta.apache.org/

USE_JAVA=	yes

WRKSRC=		${WRKDIR}/jakarta-tomcat
BUILD_DEFS+=	JAKARTA_HOME
EXTRACT_CMD=    ${DO_NADA}
NO_MTREE=

.include "../../mk/bsd.prefs.mk"

JAKARTA_HOME?=	${JAVA_HOME}/jakarta
MAKE_ENV+=	JAVA_HOME=${JAVA_HOME}

MESSAGE_FILE=	${WRKDIR}/MESSAGE

post-extract:
.for x in ${DISTFILES}
	cd ${WRKDIR} && ${EXTRACTOR} ${DISTDIR}/$x
.endfor

post-patch:
	${SED} -e s,@TOMCAT_HOME@,${JAKARTA_HOME}/tomcat,g \
		< ${WRKSRC}/build.xml > ${WRKSRC}/build.tmp
	${MV} ${WRKSRC}/build.tmp ${WRKSRC}/build.xml
	${SED} -e s,@LOCALBASE@,${LOCALBASE},g \
		< ${WRKSRC}/src/etc/tomcat.conf > ${WRKSRC}/src/etc/tomcat.tmp
	${MV} ${WRKSRC}/src/etc/tomcat.tmp ${WRKSRC}/src/etc/tomcat.conf

do-build:
	cd ${WRKSRC} && ${SH} ./build.sh

post-build:
	${SED} 's,@TOMCAT_HOME@,${JAKARTA_HOME}/tomcat,g' \
		< ${PKGDIR}/MESSAGE > ${WRKDIR}/MESSAGE

do-install:
	${MKDIR} ${JAKARTA_HOME}/tomcat
	cd ${WRKSRC} && ${SH} ./build.sh dist
	${INSTALL_DATA} ${WRKSRC}/Tomcat+Apache-HOWTO ${JAKARTA_HOME}/tomcat
	${CHMOD} +x ${JAKARTA_HOME}/tomcat/*.sh

.include "../../mk/bsd.pkg.mk"

# This needs to be after bsd.pkg.mk 
PREFIX:=        ${JAKARTA_HOME}

# work around a bug in kaffe's jar utility
# pkglint or no, this has to be after bsd.pkg.mk
.if ${PKG_JVM} == "kaffe"
DEPENDS+=	unzip-[0-9]*:../../archivers/unzip
EXTRACTOR=	${LOCALBASE}/bin/unzip -x
.else
EXTRACTOR=	${JAVA_HOME}/bin/jar xf
.endif
