# $NetBSD: Makefile,v 1.13 2002/12/26 20:52:13 jlam Exp $

DISTNAME=	jakarta-tomcat-3.2.4-src
PKGNAME=	ap-jk-3.2.4
CATEGORIES=	www
MASTER_SITES=	http://jakarta.apache.org/builds/tomcat/release/v3.2.4/src/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://jakarta.apache.org/
COMMENT=	improved connector for accessing Jakarta Tomcat or JServ from Apache

USE_BUILDLINK2=	# defined
APACHE_MODULE=	# defined

EXTRACT_ELEMENTS=	${DISTNAME}/src/native
WRKSRC=		${WRKDIR}/${DISTNAME}/src/native/apache1.3

do-build:
	cd ${WRKSRC} &&							\
	${APXS} -o mod_jk.so						\
		-I../jk ${BUILDLINK_CPPFLAGS.${PKG_JVM}}		\
		-c *.c ../jk/*.c

do-install:
	${INSTALL_DATA} ${WRKSRC}/mod_jk.so ${PREFIX}/lib/httpd

.include "../../www/apache/buildlink2.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
