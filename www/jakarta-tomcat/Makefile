# $NetBSD: Makefile,v 1.30 2002/06/19 09:10:00 abs Exp $

DISTNAME=	jakarta-tomcat-3.2.4-src
PKGNAME=	jakarta-tomcat-3.2.4
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://jakarta.apache.org/builds/jakarta-tomcat/release/v3.2.4/src/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://jakarta.apache.org/
COMMENT=	the Apache Project's Java Servlet 2.2 and JSP 1.1 server

DEPENDS+=	jakarta-servletapi-[0-9]*:../../www/jakarta-servletapi
DEPENDS+=	jakarta-ant>=1.4.1:../../devel/jakarta-ant

USE_JAVA=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}

CLASSPATH:=	${LOCALBASE}/lib/java/servlet.jar:${LOCALBASE}/lib/jaxp.jar:${LOCALBASE}/lib/parser.jar:${CLASSPATH}
MAKEFILE=	build.xml
MAKE_ENV+=	JAVA_HOME=${JAVA_HOME} CLASSPATH=${CLASSPATH}
ALL_TARGET=	main
INSTALL_TARGET=	dist

DEINSTALL_FILE=		${PKGDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

post-patch:
	${SED}	-e "s|@PREFIX@|${PREFIX}|g"				\
		-e "s|@JAVA_HOME@|${JAVA_HOME}|g"			\
		${WRKSRC}/src/etc/workers.properties > ${WRKSRC}/src/etc/workers.properties.tmp
		${MV} ${WRKSRC}/src/etc/workers.properties.tmp ${WRKSRC}/src/etc/workers.properties
	${RM} -f ${WRKSRC}/src/etc/workers.properties.orig
	${RM} -f ${WRKSRC}/src/share/org/apache/tomcat/facade/RequestDispatcherImpl.java.orig
	${RM} -f ${WRKSRC}/src/share/org/apache/tomcat/task/ApacheConfig.java.orig
	${RM} -f ${WRKSRC}/src/share/org/apache/tomcat/loader/AdaptiveClassLoader.java.orig

post-build:
	${SED}	-e "s|@PREFIX@|${PREFIX}|g"				\
		${FILESDIR}/tomcat.sh > ${WRKDIR}/tomcat.sh

pre-install:
	${SED}	-e "s|@CAT@|${CAT}|g"					\
		-e "s|@CHMOD@|${CHMOD}|g"				\
		-e "s|@CP@|${CP}|g"					\
		${PKGDIR}/INSTALL > ${INSTALL_FILE}

post-install:
	${RM} ${PREFIX}/tomcat/webapps/examples.war
	${INSTALL_SCRIPT} ${WRKDIR}/tomcat.sh ${PREFIX}/etc/rc.d/tomcat
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
MAKE_PROGRAM=	${LOCALBASE}/bin/ant
MAKE_FLAGS=	-Dpkgsrc.prefix=${PREFIX}
