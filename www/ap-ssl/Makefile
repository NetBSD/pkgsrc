# $NetBSD: Makefile,v 1.33 2001/04/29 20:36:47 jlam Exp $

DISTNAME=		mod_ssl-2.8.2-1.3.19
PKGNAME=		ap-ssl-2.8.2
CATEGORIES=		www security
MASTER_SITES=		http://www.modssl.org/source/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.modssl.org/
COMMENT=		SSL/TLS protocols module for Apache

DEPENDS+=		apache-1.3.19:../../www/apache
# For "apxs":
BUILD_DEPENDS+=		perl>=${PERL5_REQD}:../../lang/perl5

CONFLICTS=		apache-1.3.[0-9] apache-*modssl-* apache6-*

HAS_CONFIGURE=		# defined
USE_SSL=		# defined

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--with-apxs=${PREFIX}/sbin/apxs
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}

APACHE_SYSCONFDIR?=	${LOCALBASE}/etc/httpd
SAMPLECONFDIR=		${PREFIX}/share/examples/mod_ssl

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

post-extract:
	cd ${WRKSRC}/pkg.contrib; ${MV} -f loadcacert.cgi loadcacert.cgi.in
	cd ${WRKSRC}/pkg.sslsup; ${MV} -f mkcert.sh mkcert.sh.in

post-build:
	${SED}	-e "s|^#!/.*|#!${PERL5}|g"				\
		${WRKSRC}/pkg.contrib/loadcacert.cgi.in 		\
		> ${WRKSRC}/pkg.contrib/loadcacert.cgi
	${SED}	-e "s|@APACHE_SYSCONFDIR@|${APACHE_SYSCONFDIR}|g"	\
		${WRKSRC}/pkg.sslsup/mkcert.sh.in			\
		> ${WRKSRC}/pkg.sslsup/mkcert.sh

pre-install:
	${SED}	-e "s|@CAT@|${CAT}|g"					\
		-e "s|@RM@|${RM}|g"					\
		-e "s|@APACHE_SYSCONFDIR@|${APACHE_SYSCONFDIR}|g"	\
		${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}	-e "s|@CAT@|${CAT}|g"					\
		-e "s|@CHMOD@|${CHMOD}|g"				\
		-e "s|@CP@|${CP}|g"					\
		-e "s|@MKDIR@|${MKDIR}|g"				\
		-e "s|@APACHE_SYSCONFDIR@|${APACHE_SYSCONFDIR}|g"	\
		${PKGDIR}/INSTALL > ${INSTALL_FILE}
	${SED}	-e "s|@PREFIX@|${PREFIX}|g"				\
		-e "s|@APACHE_SYSCONFDIR@|${APACHE_SYSCONFDIR}|g"	\
		${FILESDIR}/README.mkcert > ${WRKDIR}/README.mkcert

post-install:
	${INSTALL_DATA_DIR} ${SAMPLECONFDIR}
	${INSTALL_DATA_DIR} ${SAMPLECONFDIR}/ssl.crl
	${INSTALL_DATA_DIR} ${SAMPLECONFDIR}/ssl.crt
	${INSTALL_DATA_DIR} ${SAMPLECONFDIR}/ssl.csr
	${INSTALL_DATA_DIR} ${SAMPLECONFDIR}/ssl.key
	${INSTALL_DATA_DIR} ${SAMPLECONFDIR}/ssl.prm

	cd ${PREFIX}/lib/httpd; ${MV} -f libssl.so mod_ssl.so
	cd ${WRKSRC}/pkg.sslsup; ${INSTALL_SCRIPT} mkcert.sh		\
		${PREFIX}/sbin/mkcert
	${INSTALL_DATA} ${FILESDIR}/apache_start.conf ${SAMPLECONFDIR}

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
		${SAMPLECONFDIR}/ssl.crl
	cd ${WRKSRC}/pkg.sslcfg; ${INSTALL_DATA} README.CRT *.crt	\
		${SAMPLECONFDIR}/ssl.crt
	cd ${WRKSRC}/pkg.sslcfg; ${INSTALL_DATA} README.CSR		\
		${SAMPLECONFDIR}/ssl.csr
	cd ${WRKSRC}/pkg.sslcfg; ${INSTALL_DATA} README.KEY *.key	\
		${SAMPLECONFDIR}/ssl.key
	cd ${WRKSRC}/pkg.sslcfg; ${INSTALL_DATA} README.PRM *.prm	\
		${SAMPLECONFDIR}/ssl.prm

	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
