# $NetBSD: Makefile,v 1.5 2001/11/14 14:47:57 agc Exp $

DISTNAME=	jakarta-servletapi-3.2.3-src
PKGNAME=	jakarta-servletapi-3.2.3
CATEGORIES=	www
MASTER_SITES=	http://jakarta.apache.org/builds/jakarta-tomcat/release/v3.2.3/src/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://jakarta.apache.org/
COMMENT=	the Apache project's implementation of the JSP and Java Servlet APIs

DEPENDS+=	jakarta-ant-1.3:../../devel/jakarta-ant

USE_JAVA=	yes

MAKE_ENV+=	JAVA_HOME=${JAVA_HOME}
MAKEFILE=	build.xml
PLIST_SRC=	${PKGDIR}/PLIST ${WRKDIR}/PLIST.javadoc

WRKSRC=		${WRKDIR}/${DISTNAME}

post-build:
	rm -f ${WRKDIR}/PLIST.javadoc
	cd ${WRKDIR}/dist/servletapi/docs ; ${FIND} * -type f -print | sort | ${SED} 's:^:share/doc/java/jakarta-servletapi/:' > ${WRKDIR}/PLIST.javadoc
	cd ${WRKDIR}/dist/servletapi/docs ; ${FIND} * -type d -print | sort -r | ${SED} 's:^:@dirrm share/doc/java/jakarta-servletapi/:' >> ${WRKDIR}/PLIST.javadoc
	echo '@dirrm share/doc/java/jakarta-servletapi' >> ${WRKDIR}/PLIST.javadoc

do-install:
	${INSTALL_DATA} ${WRKDIR}/dist/servletapi/lib/servlet.jar ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/jakarta-servletapi
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/java/jakarta-servletapi
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/java/jakarta-servletapi
	cd ${WRKDIR}/dist/servletapi/docs && ${PAX} -rwpe . ${PREFIX}/share/doc/java/jakarta-servletapi

.include "../../mk/bsd.pkg.mk"
MAKE_PROGRAM=	${LOCALBASE}/bin/ant
