# $NetBSD: Makefile,v 1.116 2014/02/12 23:18:43 tron Exp $

DISTNAME=		mod_ssl-2.8.31-1.3.41
PKGNAME=		ap13-ssl-2.8.31
PKGREVISION=		6
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
.for file in ${CONFS}
CONF_FILES+=		${EGDIR}/${file} ${PKG_SYSCONFDIR}/${file}
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

INSTALLATION_DIRS+=	lib/httpd sbin \
			${EGDIR}/ssl.crl ${EGDIR}/ssl.crt ${EGDIR}/ssl.csr \
			${EGDIR}/ssl.key ${EGDIR}/ssl.prm \
			share/doc/mod_ssl \
			share/httpd/htdocs/manual/mod/mod_ssl share/mod_ssl

do-install:
	${INSTALL_LIB} ${WRKSRC}/pkg.sslmod/libssl.so \
	    ${DESTDIR}${PREFIX}/lib/httpd/mod_ssl.so
	${INSTALL_SCRIPT} ${WRKSRC}/pkg.sslsup/mkcert.sh		\
	    ${DESTDIR}${PREFIX}/sbin/mkcert

	cd ${WRKSRC}/pkg.ssldoc && ${INSTALL_DATA} *.html *.gif *.jpg	\
	    ${DESTDIR}${PREFIX}/share/httpd/htdocs/manual/mod/mod_ssl
	cd ${WRKSRC}/pkg.contrib && ${INSTALL_SCRIPT} *.sh *.cgi	\
	    ${DESTDIR}${PREFIX}/share/mod_ssl
	${INSTALL_DATA} ${WRKSRC}/README.mkcert \
	    ${DESTDIR}${PREFIX}/share/doc/mod_ssl

	cd ${WRKSRC}/pkg.sslcfg; ${RM} -f server.*
	cd ${WRKSRC}/pkg.sslcfg; ${INSTALL_DATA} README.CRL *.crl	\
	    ${DESTDIR}${EGDIR}/ssl.crl
	cd ${WRKSRC}/pkg.sslcfg; ${INSTALL_DATA} README.CRT *.crt	\
	    ${DESTDIR}${EGDIR}/ssl.crt
	cd ${WRKSRC}/pkg.sslcfg; ${INSTALL_DATA} README.CSR		\
	    ${DESTDIR}${EGDIR}/ssl.csr
	cd ${WRKSRC}/pkg.sslcfg; ${INSTALL_DATA} README.KEY *.key	\
	    ${DESTDIR}${EGDIR}/ssl.key
	cd ${WRKSRC}/pkg.sslcfg; ${INSTALL_DATA} README.PRM *.prm	\
	    ${DESTDIR}${EGDIR}/ssl.prm

.include "../../mk/bsd.pkg.mk"
