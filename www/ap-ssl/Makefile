# $NetBSD: Makefile,v 1.24 2000/10/13 21:48:01 jlam Exp $
#

DISTNAME=	mod_ssl-2.7.0-1.3.14
PKGNAME=	ap-ssl-2.7.0
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.modssl.org/source/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.modssl.org/

DEPENDS+=	apache-1.3.14:../../www/apache
# For "apxs":
BUILD_DEPENDS+=	${PERL5}:../../lang/perl5-base

CONFLICTS=	apache-1.3.[0123456789] apache-*modssl-* apache6-*

HAS_CONFIGURE=	defined
USE_SSL=	defined

MESSAGE_FILE=	${WRKDIR}/MESSAGE

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--with-apxs=${PREFIX}/sbin/apxs
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}

post-extract:
	@cd ${WRKSRC}/pkg.sslsup; ${MV} -f mkcert.sh mkcert.sh.in

post-build:
	${SED} -e "s,@PREFIX@,${PREFIX},g" \
		< ${WRKSRC}/pkg.sslsup/mkcert.sh.in \
		> ${WRKSRC}/pkg.sslsup/mkcert.sh

post-install:
	@${SED} -e "s,@PREFIX@,${PREFIX},g" \
		< ${PKGDIR}/MESSAGE > ${MESSAGE_FILE}
	@${SED} -e "s,@PREFIX@,${PREFIX},g" \
		< ${FILESDIR}/README.mkcert > ${WRKDIR}/README.mkcert

	@cd ${PREFIX}/lib/httpd; ${MV} -f libssl.so mod_ssl.so
	${INSTALL_SCRIPT} ${WRKSRC}/pkg.sslsup/mkcert.sh ${PREFIX}/sbin
	${INSTALL_DATA} ${FILESDIR}/mod_ssl.conf ${PREFIX}/etc/httpd

	${INSTALL_DATA_DIR} ${PREFIX}/share/httpd/htdocs/manual/mod/mod_ssl
	cd ${WRKSRC}/pkg.ssldoc && ${INSTALL_DATA} *.html *.gif *.jpg \
		${PREFIX}/share/httpd/htdocs/manual/mod/mod_ssl
	${INSTALL_DATA_DIR} ${PREFIX}/share/mod_ssl
	cd ${WRKSRC}/pkg.contrib && \
		${INSTALL_SCRIPT} *.sh *.cgi ${PREFIX}/share/mod_ssl
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_ssl
	${INSTALL_DATA} ${WRKDIR}/README.mkcert ${PREFIX}/share/doc/mod_ssl

	${INSTALL_DATA} ${WRKSRC}/pkg.sslcfg/README.CRL \
		`ls -1 ${WRKSRC}/pkg.sslcfg/*.crl | ${GREP} -v /server\.` \
		${PREFIX}/etc/httpd/ssl.crl
	${INSTALL_DATA} ${WRKSRC}/pkg.sslcfg/README.CRT \
		`ls -1 ${WRKSRC}/pkg.sslcfg/*.crt | ${GREP} -v /server\.` \
		${PREFIX}/etc/httpd/ssl.crt
	${INSTALL_DATA} ${WRKSRC}/pkg.sslcfg/README.CSR \
		`ls -1 ${WRKSRC}/pkg.sslcfg/*.csr | ${GREP} -v /server\.` \
		${PREFIX}/etc/httpd/ssl.csr
	${INSTALL_DATA} ${WRKSRC}/pkg.sslcfg/README.KEY \
		`ls -1 ${WRKSRC}/pkg.sslcfg/*.key | ${GREP} -v /server\.` \
		${PREFIX}/etc/httpd/ssl.key
	${INSTALL_DATA} ${WRKSRC}/pkg.sslcfg/README.PRM \
		`ls -1 ${WRKSRC}/pkg.sslcfg/*.prm | ${GREP} -v /server\.` \
		${PREFIX}/etc/httpd/ssl.prm

.include "../../mk/bsd.pkg.mk"
