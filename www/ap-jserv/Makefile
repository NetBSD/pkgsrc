# $NetBSD: Makefile,v 1.27 2004/01/24 15:23:46 grant Exp $

DISTNAME=	ApacheJServ-1.1.2
PKGNAME=	ap-jserv-1.1.2
CATEGORIES=	www java
MASTER_SITES=	http://java.apache.org/jserv/dist/

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://java.apache.org/
COMMENT=	Older Java Servlet engine for Apache Server

DEPENDS+=	{apache-1.3.9*,apache-1.3.[1-9][0-9]*,apache6-1.3.9*,apache6-1.3.[1-9][0-9]*}:../../www/apache
# yes, this needs _exactly_ version 2.0
DEPENDS+=	jsdk-2.0:../../www/jsdk20
USE_PERL5=	build	# for "apxs"

USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/src/scripts/build/unix/ltconfig
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-apxs=${LOCALBASE}/sbin/apxs
CONFIGURE_ARGS+=	--with-jdk-home=${PKG_JAVA_HOME}
CONFIGURE_ARGS+=	--with-JSDK=${PREFIX}/lib/java/jsdk.jar
CONFIGURE_ARGS+=	--with-logdir=/var/log/httpd
CONFIGURE_ARGS+=	--with-servlets=${LOCALBASE}/share/httpd/servlets
CONFIGURE_ARGS+=	--enable-EAPI

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"

JSDK_HOME=	${PKG_JAVA_HOME}/jsdk
BUILD_DEFS+=	JSDK_HOME
