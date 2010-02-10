# $NetBSD: Makefile,v 1.109 2010/02/10 03:55:18 dholland Exp $

DISTNAME=		mod_ssl-2.8.31-1.3.41
PKGNAME=		ap13-ssl-2.8.31
PKGREVISION=		2
CATEGORIES=		www security
MASTER_SITES=		http://www.modssl.org/source/ \
			ftp://ftp.pca.dfn.de/pub/tools/net/mod_ssl/source/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.modssl.org/
COMMENT=		SSL/TLS protocols module for Apache

CONFLICTS=		apache-1.3.[0-9] apache-*modssl-[0-9]* apache6-[0-9]*
CONFLICTS+=		ap-ssl-[0-9]*


APACHE_MODULE=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE:Q}

.include "../../mk/bsd.prefs.mk"

.include "../../www/apache/buildlink3.mk"
BUILDLINK_API_DEPENDS.apache+=	apache>=1.3.42

SSL_RPATH_LDFLAGS=	${LINKER_RPATH_FLAG} ${SSLBASE}/lib
FIX_RPATH+=		SSL_RPATH_LDFLAGS
MAKE_ENV+=		SSL_RPATH_LDFLAGS=${SSL_RPATH_LDFLAGS:Q}

PKG_SYSCONFVAR=		apache
PKG_SYSCONFSUBDIR?=	httpd

EGDIR=			${PREFIX}/share/examples/mod_ssl
OWN_DIRS=		${PKG_SYSCONFDIR}/ssl.crl
OWN_DIRS+=		${PKG_SYSCONFDIR}/ssl.crt
OWN_DIRS+=		${PKG_SYSCONFDIR}/ssl.csr
OWN_DIRS+=		${PKG_SYSCONFDIR}/ssl.prm
OWN_DIRS_PERMS=		${PKG_SYSCONFDIR}/ssl.key			\
			${ROOT_USER} ${ROOT_GROUP} 0700

CONF_FILES=		# empty
CONFS=			ssl.crl/Makefile.crl ssl.crl/README.CRL		\
			ssl.crt/Makefile.crt ssl.crt/README.CRT		\
			ssl.csr/README.CSR ssl.csr/README.CSR		\
			ssl.key/README.KEY ssl.prm/README.PRM
.for FILE in ${CONFS}
CONF_FILES+=		${EGDIR}/${FILE} ${PKG_SYSCONFDIR}/${FILE}
.endfor

.include "../../security/openssl/buildlink3.mk"

SUBST_CLASSES+=		paths perl
SUBST_FILES.paths=	README.mkcert pkg.sslsup/mkcert.sh
SUBST_SED.paths=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,@SH@,${SH},g'
SUBST_STAGE.paths=	post-patch
SUBST_FILES.perl=	pkg.contrib/loadcacert.cgi
SUBST_SED.perl=		-e 's,^\#!/.*,\#!${PERL5},g'
SUBST_STAGE.perl=	post-patch

post-extract:
	${CP} ${FILESDIR}/README.mkcert ${WRKSRC}

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
	${INSTALL_DATA} ${WRKSRC}/README.mkcert ${PREFIX}/share/doc/mod_ssl

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
