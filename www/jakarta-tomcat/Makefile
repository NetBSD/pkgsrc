# $NetBSD: Makefile,v 1.32 2002/12/28 21:35:04 jlam Exp $

DISTNAME=	jakarta-tomcat-${TOMCAT_VERSION}-src
PKGNAME=	${DISTNAME:S/-src$//}
TOMCAT_VERSION=	3.2.4
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://jakarta.apache.org/builds/jakarta-tomcat/release/v${TOMCAT_VERSION}/src/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://jakarta.apache.org/
COMMENT=	the Apache Project's Java Servlet 2.2 and JSP 1.1 server

DEPENDS+=	jakarta-servletapi-[0-9]*:../../www/jakarta-servletapi
DEPENDS+=	jakarta-ant>=1.4.1:../../devel/jakarta-ant

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_BUILDLINK2=	# defined
MAKEFILE=	build.xml
ALL_TARGET=	main
INSTALL_TARGET=	dist

SAMPLECONFDIR=			${PREFIX}/tomcat/conf
PKG_SYSCONFDIR.jakarta-tomcat=	${SAMPLECONFDIR}

OWN_DIRS=	${PREFIX}/tomcat
MAKE_DIRS=	${PREFIX}/tomcat/conf
MAKE_DIRS=	${PREFIX}/tomcat/logs
MAKE_DIRS=	${PREFIX}/tomcat/webapps
CFILES=		server.xml web.xml tomcat-users.xml jni_server.xml
CFILES+=	tomcat.policy workers.properties

CONF_FILES=	# empty
.for FILE in ${CFILES}
CONF_FILES+=	${SAMPLECONFDIR}/${FILE}.default ${PKG_SYSCONFDIR}/${FILE}
.endfor
RCD_SCRIPTS=	tomcat

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
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"

MAKE_PROGRAM=	${LOCALBASE}/bin/ant
MAKE_FLAGS=	-Dpkgsrc.prefix=${PREFIX}
CLASSPATH:=	${LOCALBASE}/lib/java/servlet.jar:${LOCALBASE}/lib/jaxp.jar:${LOCALBASE}/lib/parser.jar:${CLASSPATH}
