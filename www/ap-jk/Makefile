# $NetBSD: Makefile,v 1.23 2004/07/02 22:01:01 wiz Exp $

DISTNAME=	jakarta-tomcat-${TOMCAT_VERSION}-src
PKGNAME=	ap-jk-${TOMCAT_VERSION}
TOMCAT_VERSION=	3.2.4
CATEGORIES=	www java
MASTER_SITES=	http://jakarta.apache.org/builds/tomcat/release/v${TOMCAT_VERSION}/src/

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://jakarta.apache.org/
COMMENT=	Apache connector for accessing Jakarta Tomcat or Apache JServ

# XXX workaround for pax-as-tar problem in -current:
# tar: Invalid header, starting valid header search.
#
BUILD_DEPENDS+=	gtar-base-[0-9]*:../../archivers/gtar-base
GTAR=		${LOCALBASE}/bin/gtar

WRKSRC=			${WRKDIR}/${DISTNAME}/src/native/apache1.3
USE_BUILDLINK3=		# defined

EXTRACT_ELEMENTS=	${DISTNAME}/src/native

APACHE_MODULE_NAME=	mod_jk.so
APACHE_MODULE_SRC=	*.c ../jk/*.c
CPPFLAGS+=		-I../jk ${BUILDLINK_CPPFLAGS.${PKG_JVM}}

.include "../../www/apache/module.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
