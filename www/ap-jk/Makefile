# $NetBSD: Makefile,v 1.9 2002/07/24 19:45:30 jlam Exp $

DISTNAME=	jakarta-tomcat-3.2.4-src
PKGNAME=	ap-jk-3.2.4
CATEGORIES=	www
MASTER_SITES=	http://jakarta.apache.org/builds/tomcat/release/v3.2.4/src/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://jakarta.apache.org/
COMMENT=	improved connector for accessing Jakarta Tomcat or JServ from Apache

DEPENDS+=	apache{,6}-1.3.*:../../www/apache

USE_JAVA=	yes
USE_PERL5=	build	# for "apxs"

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
