# $NetBSD: Makefile,v 1.16 2003/02/17 23:05:48 grant Exp $

DISTNAME=	jakarta-tomcat-${TOMCAT_VERSION}-src
PKGNAME=	ap-jk-${TOMCAT_VERSION}
TOMCAT_VERSION=	3.2.4
CATEGORIES=	www
MASTER_SITES=	http://jakarta.apache.org/builds/tomcat/release/v${TOMCAT_VERSION}/src/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://jakarta.apache.org/
COMMENT=	Apache connector for accessing Jakarta Tomcat or Apache JServ

# XXX workaround for pax-as-tar problem in -current:
# tar: Invalid header, starting valid header search.
#
BUILD_DEPENDS+=	gtar-base:../../archivers/gtar-base
GTAR=		${LOCALBASE}/bin/gtar

USE_BUILDLINK2=		# defined

EXTRACT_ELEMENTS=	${DISTNAME}/src/native
WRKSRC=			${WRKDIR}/${DISTNAME}/src/native/apache1.3

APACHE_MODULE_NAME=	mod_jk.so
APACHE_MODULE_SRC=	*.c ../jk/*.c
CPPFLAGS+=		-I../jk ${BUILDLINK_CPPFLAGS.${PKG_JVM}}


.include "../../www/apache/module.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
