# $NetBSD: Makefile,v 1.41 2004/01/20 12:27:59 agc Exp $

DISTNAME=	jakarta-tomcat-${TOMCAT_VERSION}-src
PKGNAME=	${DISTNAME:S/-src$//}
TOMCAT_VERSION=	3.2.4
PKGREVISION=	1
CATEGORIES=	www java
MASTER_SITES=	http://jakarta.apache.org/builds/jakarta-tomcat/release/v${TOMCAT_VERSION}/src/

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://jakarta.apache.org/
COMMENT=	The Apache Project's Java Servlet 2.2 and JSP 1.1 server

DEPENDS+=	jakarta-servletapi-[0-9]*:../../www/jakarta-servletapi
DEPENDS+=	apache-ant>=1.4.1:../../devel/apache-ant

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_BUILDLINK2=	yes
MAKEFILE=	build.xml
ALL_TARGET=	main
INSTALL_TARGET=	dist

SAMPLECONFDIR=			${PREFIX}/tomcat/conf
PKG_SYSCONFDIR.jakarta-tomcat=	${SAMPLECONFDIR}

USE_PKGINSTALL=	yes
OWN_DIRS=	${PREFIX}/tomcat
OWN_DIRS+=	${PREFIX}/tomcat/conf
OWN_DIRS+=	${PREFIX}/tomcat/logs
OWN_DIRS+=	${PREFIX}/tomcat/webapps
CFILES=		server.xml web.xml tomcat-users.xml jni_server.xml
CFILES+=	tomcat.policy workers.properties

CONF_FILES=	# empty
.for FILE in ${CFILES}
CONF_FILES+=	${SAMPLECONFDIR}/${FILE}.default ${PKG_SYSCONFDIR}/${FILE}
.endfor
RCD_SCRIPTS=	tomcat

FILES_SUBST+=	JAVA_HOME=${PKG_JAVA_HOME}

post-patch:
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM} -f
	for file in ${WRKSRC}/src/etc/workers.properties; do		\
		${SED}	-e "s|@PREFIX@|${PREFIX}|g"			\
			-e "s|@JAVA_HOME@|${PKG_JAVA_HOME}|g"		\
			$$file > $$file.tmp;				\
		${MV} -f $$file.tmp $$file;				\
	done

post-install:
	${RM} ${PREFIX}/tomcat/webapps/examples.war

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"

MAKE_PROGRAM=	${LOCALBASE}/bin/ant
MAKE_FLAGS=	-Dpkgsrc.prefix=${PREFIX}
CLASSPATH:=	${LOCALBASE}/lib/java/servlet.jar:${LOCALBASE}/lib/jaxp.jar:${LOCALBASE}/lib/parser.jar:${CLASSPATH}
