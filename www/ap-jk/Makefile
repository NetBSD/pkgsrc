# $NetBSD: Makefile,v 1.4 2001/05/12 15:01:45 jlam Exp $

DISTNAME=	jakarta-tomcat-3.2.1-src
PKGNAME=	ap-jk-3.2.1
CATEGORIES=	www
MASTER_SITES=	http://jakarta.apache.org/builds/tomcat/release/v3.2.1/src/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://jakarta.apache.org/
COMMENT=	improved connector for accessing Jakarta Tomcat or JServ from Apache

DEPENDS+=	apache-*:../../www/apache

USE_JAVA=	yes
# For "apxs":
BUILD_DEPENDS+=	perl>=${PERL5_REQD}:../../lang/perl5

EXTRACT_ELEMENTS=	${DISTNAME}/src/native
WRKSRC=		${WRKDIR}/${DISTNAME}/src/native/apache1.3

do-build:
	(cd ${WRKSRC} && \
		${LOCALBASE}/sbin/apxs -o mod_jk.so \
		-I../jk -I${JAVA_HOME}/include \
		-I${JAVA_HOME}/include/netbsd \
		-I${JAVA_HOME}/include/linux \
		-c *.c ../jk/*.c)

do-install:
	${INSTALL_DATA} ${WRKSRC}/mod_jk.so ${PREFIX}/lib/httpd

.include "../../mk/bsd.pkg.mk"
