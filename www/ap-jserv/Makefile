# $NetBSD: Makefile,v 1.19 2001/05/20 05:23:28 jonb Exp $

DISTNAME=	ApacheJServ-1.1.2
PKGNAME=	ap-jserv-1.1.2
CATEGORIES=	www
MASTER_SITES=	http://java.apache.org/jserv/dist/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://java.apache.org/
COMMENT=	older Java Servlet engine for Apache Server

DEPENDS+=	apache{,6}>=1.3.9:../../www/apache
# yes, this needs _exactly_ version 2.0
DEPENDS+=	jsdk-2.0:../../www/jsdk20
# For "apxs":
BUILD_DEPENDS=	perl>=${PERL5_REQD}:../../lang/perl5

.include "../../mk/bsd.prefs.mk"

USE_JAVA=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/src/scripts/build/unix/ltconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-apxs=${LOCALBASE}/sbin/apxs --with-jdk-home=${JAVA_HOME} \
	--with-JSDK=${PREFIX}/lib/java/jsdk.jar --with-logdir=/var/log/httpd \
	--with-servlets=${LOCALBASE}/share/httpd/servlets -enable-EAPI

.include "../../mk/bsd.pkg.mk"

JSDK_HOME=	${JAVA_HOME}/jsdk
BUILD_DEFS+=	JSDK_HOME
