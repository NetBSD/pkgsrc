# $NetBSD: Makefile,v 1.1.1.1 2001/03/20 19:43:29 jwise Exp $

DISTNAME=	jakarta-servletapi-3.2-src
PKGNAME=	jakarta-servletapi-3.2.1
CATEGORIES=	www
MASTER_SITES=	http://jakarta.apache.org/builds/tomcat/release/v3.2.1/src/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://jakarta.apache.org/
COMMENT=	the Apache project's implementation of the JSP and Java Servlet APIs

DEPENDS+=	jakarta-ant-1.3:../../devel/jakarta-ant

USE_JAVA=	yes

MAKE_ENV+=	JAVA_HOME=${JAVA_HOME}
MAKEFILE=	build.xml

WRKSRC=		${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_DATA} ${WRKDIR}/dist/servletapi/lib/servlet.jar ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/jakarta-servletapi
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/jakarta-servletapi/api
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/java/jakarta-servletapi
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/java/jakarta-servletapi
	${INSTALL_DATA} ${WRKDIR}/dist/servletapi/docs/api/* ${PREFIX}/share/doc/java/jakarta-servletapi/api

.include "../../mk/bsd.pkg.mk"
MAKE_PROGRAM=	${LOCALBASE}/bin/ant
