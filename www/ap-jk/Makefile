# $NetBSD: Makefile,v 1.2 2001/04/21 13:42:39 wiz Exp $

DISTNAME=	jakarta-tomcat-3.2.1-src
PKGNAME=	ap-jk-3.2.1
CATEGORIES=	www
MASTER_SITES=	http://jakarta.apache.org/builds/tomcat/release/v3.2.1/src/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://jakarta.apache.org/
COMMENT=	improved connector for accessing Jakarta Tomcat or JServ from Apache

DEPENDS+=	apache-*:../../www/apache

USE_JAVA=	yes
USE_PERL=	yes

EXTRACT_ELEMENTS=	${DISTNAME}/src/native
WRKSRC=		${WRKDIR}/${DISTNAME}/src/native/apache1.3

do-build:
	(cd ${WRKSRC} && \
		${LOCALBASE}/sbin/apxs -o mod_jk.so \
		-I../jk -I${JAVA_HOME}/include -I${JAVA_HOME}/include/netbsd \
		-c *.c ../jk/*.c)

do-install:
	${INSTALL_DATA} ${WRKSRC}/mod_jk.so ${PREFIX}/lib/httpd

.include "../../mk/bsd.pkg.mk"
