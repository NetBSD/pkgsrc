# $NetBSD: Makefile,v 1.14 2002/12/28 20:50:21 jlam Exp $

DISTNAME=	jakarta-tomcat-${TOMCAT_VERSION}-src
PKGNAME=	ap-jk-${TOMCAT_VERSION}
TOMCAT_VERSION=	3.2.4
CATEGORIES=	www
MASTER_SITES=	http://jakarta.apache.org/builds/tomcat/release/v${TOMCAT_VERSION}/src/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://jakarta.apache.org/
COMMENT=	Apache connector for accessing Jakarta Tomcat or Apache JServ

USE_BUILDLINK2=		# defined
APACHE_MODULE=		# defined

EXTRACT_ELEMENTS=	${DISTNAME}/src/native
WRKSRC=			${WRKDIR}/${DISTNAME}/src/native/apache1.3

do-build:
	cd ${WRKSRC} &&							\
	${APXS} -o mod_jk.so						\
		-I../jk ${BUILDLINK_CPPFLAGS.${PKG_JVM}}		\
		-c *.c ../jk/*.c

do-install:
	cd ${WRKSRC} && ${APXS} -i mod_jk.so

.include "../../www/apache/buildlink2.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
