# $NetBSD: Makefile,v 1.5 2010/02/16 14:52:33 joerg Exp $

DISTNAME=	tomcat-connectors-${JK_VERSION}-src
PKGNAME=	${APACHE_PKG_PREFIX}-jk-${JK_VERSION}

MAKE_PARAMS+=		USE_APXS=1
MAKE_PARAMS+=		WITH_APXS=${APXS}

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_APACHE_ACCEPTED=	apache2 apache22

INSTALLATION_DIRS+=	lib/httpd

do-install:
	${PREFIX}/share/httpd/build/instdso.sh \
	    SH_LIBTOOL=${PREFIX}/share/httpd/build/libtool \
	    ${WRKSRC}/apache-2.0/mod_jk.la \
	    ${DESTDIR}${PREFIX}/lib/httpd

.include "../../www/ap-jk/Makefile.common"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
