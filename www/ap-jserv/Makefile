# $NetBSD: Makefile,v 1.1.1.1 2000/01/14 20:59:01 jwise Exp $

DISTNAME=	ApacheJServ-1.1b3
PKGNAME=	ap-jserv-1.1b3
CATEGORIES=	www
MASTER_SITES=	http://java.apache.org/jserv/dist/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://java.apache.org/

DEPENDS+=	apache-1.3.*:../../www/apache
# yes, this needs _exactly_ version 2.0
DEPENDS+=	jsdk-2.0:../../www/jsdk20
# For "apxs":
BUILD_DEPENDS=	${LOCALBASE}/bin/perl:../../lang/perl5

.include "../../mk/bsd.prefs.mk"

USE_JAVA=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/src/scripts/build/unix/ltconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-apxs=${LOCALBASE}/sbin/apxs --with-jdk-home=${JAVA_HOME} \
	--with-JSDK=${JSDK_HOME}/lib/jsdk.jar --with-logdir=/var/log/httpd \
	--with-servlets=${LOCALBASE}/share/httpd/servlets

.include "../../mk/bsd.pkg.mk"
JSDK_HOME=	${JAVA_HOME}/jsdk
BUILD_DEFS+=	JSDK_HOME
