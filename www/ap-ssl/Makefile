# $NetBSD: Makefile,v 1.41 2001/11/19 16:23:12 jlam Exp $

DISTNAME=		mod_ssl-2.8.5-1.3.22
PKGNAME=		ap-ssl-2.8.5
CATEGORIES=		www security
MASTER_SITES=		http://www.modssl.org/source/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.modssl.org/
COMMENT=		SSL/TLS protocols module for Apache

DEPENDS+=		apache>=1.3.22:../../www/apache
# For "apxs":
BUILD_DEPENDS+=		perl>=${PERL5_REQD}:../../lang/perl5

CONFLICTS=		apache-1.3.[0-9] apache-*modssl-[0-9]* apache6-[0-9]*

HAS_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--with-apxs=${PREFIX}/sbin/apxs
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_DIR}
MAKE_ENV+=		SSL_RPATH_LDFLAGS="-R${SSLBASE}/lib"

APACHE_SYSCONFDIR?=	${CONFDIR}/httpd
BUILD_DEFS+=		APACHE_SYSCONFDIR
FILES_SUBST+=		APACHE_SYSCONFDIR=${APACHE_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/mod_ssl
CONF_FILES=	${EGDIR}/apache_start.conf				\
		${APACHE_SYSCONFDIR}/apache_start.conf
SUPPORT_FILES=	${EGDIR}/ssl.crl/Makefile.crl				\
		${APACHE_SYSCONFDIR}/ssl.crl/Makefile.crl
SUPPORT_FILES+=	${EGDIR}/ssl.crl/README.CRL				\
		${APACHE_SYSCONFDIR}/ssl.crl/README.CRL
SUPPORT_FILES+=	${EGDIR}/ssl.crt/Makefile.crt				\
		${APACHE_SYSCONFDIR}/ssl.crt/Makefile.crt
SUPPORT_FILES+=	${EGDIR}/ssl.crt/README.CRT				\
		${APACHE_SYSCONFDIR}/ssl.crt/README.CRT
SUPPORT_FILES+=	${EGDIR}/ssl.crt/ca-bundle.crt				\
		${APACHE_SYSCONFDIR}/ssl.crt/ca-bundle.crt
SUPPORT_FILES+=	${EGDIR}/ssl.csr/README.CSR				\
		${APACHE_SYSCONFDIR}/ssl.csr/README.CSR
SUPPORT_FILES+=	${EGDIR}/ssl.key/README.KEY				\
		${APACHE_SYSCONFDIR}/ssl.key/README.KEY
SUPPORT_FILES+=	${EGDIR}/ssl.prm/README.PRM				\
		${APACHE_SYSCONFDIR}/ssl.prm/README.PRM

post-extract:
	cd ${WRKSRC}/pkg.contrib; ${MV} -f loadcacert.cgi loadcacert.cgi.in
	cd ${WRKSRC}/pkg.sslsup; ${MV} -f mkcert.sh mkcert.sh.in

post-build:
	${SED}	-e "s|^#!/.*|#!${PERL5}|g"				\
		${WRKSRC}/pkg.contrib/loadcacert.cgi.in 		\
		> ${WRKSRC}/pkg.contrib/loadcacert.cgi
	${SED} ${FILES_SUBST_SED}					\
		${WRKSRC}/pkg.sslsup/mkcert.sh.in			\
		> ${WRKSRC}/pkg.sslsup/mkcert.sh

pre-install:
	${SED} ${FILES_SUBST_SED}					\
		${FILESDIR}/README.mkcert > ${WRKDIR}/README.mkcert

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${EGDIR}/ssl.crl
	${INSTALL_DATA_DIR} ${EGDIR}/ssl.crt
	${INSTALL_DATA_DIR} ${EGDIR}/ssl.csr
	${INSTALL_DATA_DIR} ${EGDIR}/ssl.key
	${INSTALL_DATA_DIR} ${EGDIR}/ssl.prm

	cd ${PREFIX}/lib/httpd; ${MV} -f libssl.so mod_ssl.so
	cd ${WRKSRC}/pkg.sslsup; ${INSTALL_SCRIPT} mkcert.sh		\
		${PREFIX}/sbin/mkcert
	${INSTALL_DATA} ${FILESDIR}/apache_start.conf ${EGDIR}

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
		${EGDIR}/ssl.crl
	cd ${WRKSRC}/pkg.sslcfg; ${INSTALL_DATA} README.CRT *.crt	\
		${EGDIR}/ssl.crt
	cd ${WRKSRC}/pkg.sslcfg; ${INSTALL_DATA} README.CSR		\
		${EGDIR}/ssl.csr
	cd ${WRKSRC}/pkg.sslcfg; ${INSTALL_DATA} README.KEY *.key	\
		${EGDIR}/ssl.key
	cd ${WRKSRC}/pkg.sslcfg; ${INSTALL_DATA} README.PRM *.prm	\
		${EGDIR}/ssl.prm

	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
