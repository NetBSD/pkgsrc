# $NetBSD: Makefile,v 1.15 2000/04/24 13:45:52 tron Exp $
#

DISTNAME=	mod_ssl-2.6.3-1.3.12
PKGNAME=	ap-ssl-2.6.3
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.modssl.org/source/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.modssl.org/

DEPENDS+=	openssl>=0.9.5:../../security/openssl
DEPENDS+=	apache-1.3.12:../../www/apache
# For "apxs":
BUILD_DEPENDS+=	${LOCALBASE}/bin/perl:../../lang/perl5

CONFLICTS=	apache-1.3.[0123456789] apache-*modssl-* apache6-*

HAS_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

fetch-depends:
.if !defined(USE_RSAREF2) || ${USE_RSAREF2} != YES && ${USE_RSAREF2} != NO
	@${ECHO} ""
	@${ECHO} "The variable USE_RSAREF2 must be set to either YES or NO"
	@${ECHO} "in order to build this package.  People with no RSA"
	@${ECHO} "license MUST set this variable to YES.  Users outside"
	@${ECHO} "the USA MUST set this variable to NO.  RSA licensees may"
	@${ECHO} "choose -- NO is faster."
	@${FALSE}
.endif

CONFIGURE_ARGS+=	--with-apxs=${PREFIX}/sbin/apxs --with-ssl=${PREFIX}
.if defined(USE_RSAREF2) && ${USE_RSAREF2} == YES
CONFIGURE_ARGS+=	--with-rsa=${PREFIX}/lib
.endif

post-install:
	@${MV} ${PREFIX}/lib/httpd/libssl.so ${PREFIX}/lib/httpd/mod_ssl.so
	${INSTALL_DATA_DIR} ${PREFIX}/share/httpd/htdocs/manual/mod/mod_ssl
	cd ${WRKSRC}/pkg.ssldoc && \
		${INSTALL_DATA} *.html *.gif *.jpg ${PREFIX}/share/httpd/htdocs/manual/mod/mod_ssl/
	${INSTALL_DATA_DIR} ${PREFIX}/share/mod_ssl
	cd ${WRKSRC}/pkg.contrib && \
		${INSTALL_SCRIPT} *.sh *.cgi ${PREFIX}/share/mod_ssl/
	${INSTALL_DATA} ${WRKSRC}/pkg.sslcfg/README.CRL \
		${WRKSRC}/pkg.sslcfg/*.crl ${PREFIX}/etc/httpd/ssl.crl/
	${INSTALL_DATA} ${WRKSRC}/pkg.sslcfg/README.CRT \
		${WRKSRC}/pkg.sslcfg/*.crt ${PREFIX}/etc/httpd/ssl.crt/
	${INSTALL_DATA} ${WRKSRC}/pkg.sslcfg/README.CSR \
		${WRKSRC}/pkg.sslcfg/*.csr ${PREFIX}/etc/httpd/ssl.csr/
	${INSTALL_DATA} ${WRKSRC}/pkg.sslcfg/README.KEY \
		${WRKSRC}/pkg.sslcfg/*.key ${PREFIX}/etc/httpd/ssl.key/

.include "../../mk/bsd.pkg.mk"
