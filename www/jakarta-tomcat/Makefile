# $NetBSD: Makefile,v 1.26 2002/03/26 16:37:26 abs Exp $

DISTNAME=	${PKGNAME}-src
PKGNAME=	jakarta-tomcat-3.2.3
CATEGORIES=	www
MASTER_SITES=	http://jakarta.apache.org/builds/jakarta-tomcat/release/v3.2.3/src/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://jakarta.apache.org/
COMMENT=	the Apache Project's Java Servlet 2.2 and JSP 1.1 server

DEPENDS+=	jakarta-servletapi-[0-9]*:../../www/jakarta-servletapi

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

post-build:
	${SED}	-e "s|@PREFIX@|${PREFIX}|g"				\
		${FILESDIR}/tomcat.sh > ${WRKDIR}/tomcat.sh

pre-install:
	${SED}	-e "s|@CAT@|${CAT}|g"					\
		-e "s|@CHMOD@|${CHMOD}|g"				\
		-e "s|@CP@|${CP}|g"					\
		${PKGDIR}/INSTALL > ${INSTALL_FILE}

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/tomcat.sh ${PREFIX}/etc/rc.d/tomcat
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
MAKE_PROGRAM=	${LOCALBASE}/bin/ant
MAKE_FLAGS=	-Dpkgsrc.prefix=${PREFIX}
