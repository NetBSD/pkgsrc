# $NetBSD: Makefile,v 1.20 2004/01/12 09:46:04 cjep Exp $

DISTNAME=	jakarta-tomcat-${TOMCAT_VERSION}-src
PKGNAME=	ap-jk-${TOMCAT_VERSION}
TOMCAT_VERSION=	3.2.4
WRKSRC=		${WRKDIR}/${DISTNAME}/src/native/apache1.3
CATEGORIES=	www java
MASTER_SITES=	http://jakarta.apache.org/builds/tomcat/release/v${TOMCAT_VERSION}/src/

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://jakarta.apache.org/
COMMENT=	Apache connector for accessing Jakarta Tomcat or Apache JServ

# XXX workaround for pax-as-tar problem in -current:
# tar: Invalid header, starting valid header search.
#
BUILD_DEPENDS+=	gtar-base:../../archivers/gtar-base
GTAR=		${LOCALBASE}/bin/gtar

USE_BUILDLINK2=		# defined

EXTRACT_ELEMENTS=	${DISTNAME}/src/native

APACHE_MODULE_NAME=	mod_jk.so
APACHE_MODULE_SRC=	*.c ../jk/*.c
CPPFLAGS+=		-I../jk ${BUILDLINK_CPPFLAGS.${PKG_JVM}}

.include "../../www/apache/module.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
