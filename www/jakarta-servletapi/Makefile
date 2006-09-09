# $NetBSD: Makefile,v 1.26 2006/09/09 02:46:09 obache Exp $

DISTNAME=	jakarta-servletapi-${TOMCAT_VERSION}-src
PKGNAME=	${DISTNAME:S/-src$//}
TOMCAT_VERSION=	3.2.4
PKGREVISION=	1
CATEGORIES=	www java
MASTER_SITES=	http://jakarta.apache.org/builds/jakarta-tomcat/release/v${TOMCAT_VERSION}/src/

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://jakarta.apache.org/
COMMENT=	The Apache project's implementation of the JSP and Java Servlet APIs

BUILD_DEPENDS+=	apache-ant>=1.4.1:../../devel/apache-ant

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_JAVA2=	yes
MAKE_FILE=	build.xml
PLIST_SRC=	${PKGDIR}/PLIST ${WRKDIR}/PLIST.javadoc

DOCDIR=		share/doc/java/jakarta-servletapi

ALL_ENV+=	JAVACMD=${PKG_JAVA_HOME}/bin/java

post-build:
	${RM} -f ${WRKDIR}/PLIST.javadoc
	( cd ${WRKDIR}/dist/servletapi/docs;				\
	  ${FIND} * -type f -print | ${SORT}				\
		| ${SED} 's:^:${DOCDIR}/:';				\
	  ${FIND} * -type d -print | ${SORT} -r				\
		| ${SED} 's:^:@dirrm ${DOCDIR}/:';			\
	  ${ECHO} '@dirrm ${DOCDIR}'					\
	) > ${WRKDIR}/PLIST.javadoc

do-install:
	${INSTALL_DATA} ${WRKDIR}/dist/servletapi/lib/servlet.jar	\
		${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/${DOCDIR}
	cd ${WRKDIR}/dist/servletapi/docs && ${PAX} -rw -pp . ${PREFIX}/${DOCDIR}

.include "../../mk/java-vm.mk"
.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"

MAKE_PROGRAM=	${LOCALBASE}/bin/ant
MAKE_FLAGS=	# empty
