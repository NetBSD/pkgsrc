# $NetBSD: Makefile,v 1.5 2003/02/17 17:35:22 grant Exp $
#

DISTNAME=	mod_layout-3.2
PKGNAME=	${DISTNAME:C|mod_|ap-|}
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.tangent.org/pub/apache/ \
		http://software.tangent.org/download/

MAINTAINER=	grant@netbsd.org
HOMEPAGE=	http://software.tangent.org/
COMMENT=	Apache module to wrap static or dynamic content

LAYOUT_DIR=	${PREFIX}/share/httpd/htdocs/manual/mod/mod_layout

APACHE_MODULE_NAME=	mod_layout.so
APACHE_MODULE_SRC=	*.c

post-install:
	${INSTALL_DATA_DIR} ${LAYOUT_DIR}
	${INSTALL_DATA} ${WRKSRC}/faq.html ${LAYOUT_DIR}
	${INSTALL_DATA_DIR} ${LAYOUT_DIR}/directives
	cd ${WRKSRC}/directives; ${PAX} -rw . ${LAYOUT_DIR}/directives

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
