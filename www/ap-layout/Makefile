# $NetBSD: Makefile,v 1.1.1.1 2002/02/25 02:55:22 grant Exp $
#

DISTNAME=	mod_layout-3.0.4
PKGNAME=	ap-layout-3.0.4
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.tangent.org/pub/apache/ \
		http://software.tangent.org/download/

MAINTAINER=	grant@netbsd.org
HOMEPAGE=	http://software.tangent.org/
COMMENT=	Apache module to wrap static or dynamic content

DEPENDS+=	apache{,6}-1.3.*:../../www/apache
# For "apxs":
BUILD_DEPENDS=	perl>=${PERL5_REQD}:../../lang/perl5

LAYOUT_DIR=	${PREFIX}/share/httpd/htdocs/manual/mod/mod_layout

do-build:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -c -o mod_layout.so *.c

do-install:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -i mod_layout.so
	${INSTALL_DATA_DIR} ${LAYOUT_DIR}
	${INSTALL_DATA} ${WRKSRC}/faq.html ${LAYOUT_DIR}
	${INSTALL_DATA_DIR} ${LAYOUT_DIR}/directives
	cd ${WRKSRC}/directives; ${PAX} -rw . ${LAYOUT_DIR}/directives

.include "../../mk/bsd.pkg.mk"
