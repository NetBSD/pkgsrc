# $NetBSD: Makefile,v 1.9 1999/07/23 18:20:04 itojun Exp $
#

DISTNAME=	mod_ssl-2.2.8-1.3.6
PKGNAME=	ap-ssl-2.2.8
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.modssl.org/source/

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.modssl.org/

DEPENDS=	openssl-0.9.2b:../../security/openssl \
		apache-1.3.6p0:../../www/apache
# For "apxs":
BUILD_DEPENDS=	${LOCALBASE}/bin/perl:../../lang/perl5

CONFLICTS=	apache-1.3.[012] apache-*modssl-* apache6-*

.include "../../mk/bsd.prefs.mk"

fetch-depends:
.if !defined(USE_RSAREF2) || ${USE_RSAREF2} != YES && ${USE_RSAREF2} != NO
	@${ECHO}
	@${ECHO} The variable USE_RSAREF2 must be set to either YES or NO
	@${ECHO} in order to build this package.  People with no RSA
	@${ECHO} license MUST set this variable to YES.  Users outside
	@${ECHO} the USA MUST set this variable to NO.  RSA licensees may
	@${ECHO} choose -- NO is faster.
	@${FALSE}
.endif

LDFLAGS+=	-L${PREFIX}/lib -lcrypto -lssl
CPPFLAGS+=	-I${PREFIX}/include/openssl
.if defined(USE_RSAREF2) && ${USE_RSAREF2} == YES
LDFLAGS+=	-lrsaref
.endif

# Since we don't have the Apache source tree to work with, we have to pretend
# to get all the appropriate config information and compile with apxs.
do-build:
	@cd ${WRKSRC}/pkg.sslmod && ${PREFIX}/sbin/apxs -c -o mod_ssl.so \
		${CPPFLAGS} -DSSL_COMPAT -DMOD_SSL_VERSION=\\\"2.2.8\\\" \
		-DSSL_PRODUCT_NAME=\\\"mod_ssl\\\" \
		-DSSL_PRODUCT_VERSION=\\\"2.2.8\\\" *.c
	cd ${WRKSRC}/pkg.sslsup && ${LINK.c} -o ca-fix ca-fix.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pkg.sslsup/ca-fix ${PREFIX}/bin/
	@cd ${WRKSRC}/pkg.sslmod && ${PREFIX}/sbin/apxs -i mod_ssl.so
	${INSTALL_DATA_DIR} ${PREFIX}/share/httpd/htdocs/manual/mod/mod_ssl
	cd ${WRKSRC}/pkg.ssldoc && \
		${INSTALL_DATA} *.html *.gif *.jpg ${PREFIX}/share/httpd/htdocs/manual/mod/mod_ssl/
	${INSTALL_DATA_DIR} ${PREFIX}/share/mod_ssl
	cd ${WRKSRC}/pkg.contrib && \
		${INSTALL_SCRIPT} *.sh *.cgi ${PREFIX}/share/mod_ssl/
	${INSTALL_DATA} ${WRKSRC}/pkg.sslcfg/Makefile ${WRKSRC}/pkg.sslcfg/README.CRT \
		${WRKSRC}/pkg.sslcfg/*.crt ${PREFIX}/etc/httpd/ssl.crt/
	${INSTALL_DATA} ${WRKSRC}/pkg.sslcfg/README.CSR \
		${WRKSRC}/pkg.sslcfg/*.csr ${PREFIX}/etc/httpd/ssl.csr/
	${INSTALL_DATA} ${WRKSRC}/pkg.sslcfg/README.KEY \
		${WRKSRC}/pkg.sslcfg/*.key ${PREFIX}/etc/httpd/ssl.key/

.include "../../mk/bsd.pkg.mk"
