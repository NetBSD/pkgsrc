# $NetBSD: Makefile,v 1.29 2001/02/07 15:23:29 tron Exp $

DISTNAME=		mod_ssl-2.8.0-1.3.17
PKGNAME=		ap-ssl-2.8.0
CATEGORIES=		www security
MASTER_SITES=		http://www.modssl.org/source/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.modssl.org/

DEPENDS+=		apache-1.3.17.1:../../www/apache
# For "apxs":
BUILD_DEPENDS+=		${PERL5}:../../lang/perl5-base

CONFLICTS=		apache-1.3.[0-9] apache-*modssl-* apache6-*

HAS_CONFIGURE=		# defined
USE_SSL=		# defined

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--with-apxs=${PREFIX}/sbin/apxs
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}

post-extract:
	cd ${WRKSRC}/pkg.contrib; ${MV} -f loadcacert.cgi loadcacert.cgi.in
	cd ${WRKSRC}/pkg.sslsup; ${MV} -f mkcert.sh mkcert.sh.in

post-build:
	cd ${WRKSRC}; ${SED} -e "s|^#!/.*|#!${PERL5}|g"			\
		pkg.contrib/loadcacert.cgi.in > pkg.contrib/loadcacert.cgi
	cd ${WRKSRC}; ${SED} -e "s|@PREFIX@|${PREFIX}|g"		\
		pkg.sslsup/mkcert.sh.in > pkg.sslsup/mkcert.sh

post-install:
	${SED} -e "s|@PREFIX@|${PREFIX}|g"				\
		${FILESDIR}/README.mkcert > ${WRKDIR}/README.mkcert

	cd ${PREFIX}/lib/httpd; ${MV} -f libssl.so mod_ssl.so
	cd ${WRKSRC}/pkg.sslsup; ${INSTALL_SCRIPT} mkcert.sh ${PREFIX}/sbin
	${INSTALL_DATA} ${FILESDIR}/apache_start.conf ${PREFIX}/etc/httpd

	${INSTALL_DATA_DIR} ${PREFIX}/share/httpd/htdocs/manual/mod/mod_ssl
	cd ${WRKSRC}/pkg.ssldoc; ${INSTALL_DATA} *.html *.gif *.jpg	\
		${PREFIX}/share/httpd/htdocs/manual/mod/mod_ssl
	${INSTALL_DATA_DIR} ${PREFIX}/share/mod_ssl
	cd ${WRKSRC}/pkg.contrib; ${INSTALL_SCRIPT} *.sh *.cgi		\
		${PREFIX}/share/mod_ssl
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_ssl
	${INSTALL_DATA} ${WRKDIR}/README.mkcert ${PREFIX}/share/doc/mod_ssl

	cd ${WRKSRC}/pkg.sslcfg; ${RM} -f server.*
	cd ${WRKSRC}/pkg.sslcfg; ${INSTALL_DATA} README.CRL *.crl	\
		${PREFIX}/etc/httpd/ssl.crl
	cd ${WRKSRC}/pkg.sslcfg; ${INSTALL_DATA} README.CRT *.crt	\
		${PREFIX}/etc/httpd/ssl.crt
	cd ${WRKSRC}/pkg.sslcfg; ${INSTALL_DATA} README.CSR		\
		${PREFIX}/etc/httpd/ssl.csr
	cd ${WRKSRC}/pkg.sslcfg; ${INSTALL_DATA} README.KEY *.key	\
		${PREFIX}/etc/httpd/ssl.key
	cd ${WRKSRC}/pkg.sslcfg; ${INSTALL_DATA} README.PRM *.prm	\
		${PREFIX}/etc/httpd/ssl.prm

.include "../../mk/bsd.pkg.mk"
