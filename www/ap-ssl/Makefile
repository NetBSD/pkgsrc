# $NetBSD: Makefile,v 1.78 2004/04/26 20:28:54 jlam Exp $

DISTNAME=		mod_ssl-2.8.16-1.3.29
PKGNAME=		ap-ssl-2.8.16
PKGREVISION=		2
CATEGORIES=		www security
MASTER_SITES=		http://www.modssl.org/source/ \
			ftp://ftp.pca.dfn.de/pub/tools/net/mod_ssl/source/ \
			ftp://ftp.funet.fi/pub/crypt/cryptography/libs/modssl/source/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.modssl.org/
COMMENT=		SSL/TLS protocols module for Apache

CONFLICTS=		apache-1.3.[0-9] apache-*modssl-[0-9]* apache6-[0-9]*

BUILDLINK_DEPENDS.apache=	apache>=1.3.29

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
APACHE_MODULE=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}

.include "../../mk/bsd.prefs.mk"

SSL_RPATH_LDFLAGS=	${RPATH_FLAG}${SSLBASE}/lib
FIX_RPATH+=		SSL_RPATH_LDFLAGS
MAKE_ENV+=		SSL_RPATH_LDFLAGS="${SSL_RPATH_LDFLAGS}"

PKG_SYSCONFVAR=		apache
PKG_SYSCONFSUBDIR?=	httpd

EGDIR=			${PREFIX}/share/examples/mod_ssl
OWN_DIRS=		${PKG_SYSCONFDIR}/ssl.crl
OWN_DIRS+=		${PKG_SYSCONFDIR}/ssl.crt
OWN_DIRS+=		${PKG_SYSCONFDIR}/ssl.csr
OWN_DIRS+=		${PKG_SYSCONFDIR}/ssl.prm
OWN_DIRS_PERMS=		${PKG_SYSCONFDIR}/ssl.key			\
			${ROOT_USER} ${ROOT_GROUP} 0700

SUPPORT_FILES=		# empty
SUPPS=			ssl.crl/Makefile.crl ssl.crl/README.CRL		\
			ssl.crt/Makefile.crt ssl.crt/README.CRT		\
			ssl.crt/ca-bundle.crt ssl.crt/README.CSR	\
			ssl.key/README.KEY ssl.prm/README.PRM
.for FILE in ${SUPPS}
SUPPORT_FILES+=		${EGDIR}/${FILE} ${PKG_SYSCONFDIR}/${FILE}
.endfor

.include "../../security/openssl/buildlink3.mk"
.include "../../www/apache/buildlink3.mk"

post-extract:
	cd ${WRKSRC}/pkg.contrib; ${MV} -f loadcacert.cgi loadcacert.cgi.in
	cd ${WRKSRC}/pkg.sslsup; ${MV} -f mkcert.sh mkcert.sh.in

post-build:
	@${SED}	-e "s|^#!/.*|#!${PERL5}|g"				\
		${WRKSRC}/pkg.contrib/loadcacert.cgi.in 		\
		> ${WRKSRC}/pkg.contrib/loadcacert.cgi
	@${SED} ${FILES_SUBST_SED}					\
		${WRKSRC}/pkg.sslsup/mkcert.sh.in			\
		> ${WRKSRC}/pkg.sslsup/mkcert.sh

pre-install:
	@${SED} ${FILES_SUBST_SED}					\
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

.include "../../mk/bsd.pkg.mk"
