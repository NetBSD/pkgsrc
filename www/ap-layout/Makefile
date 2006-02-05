# $NetBSD: Makefile,v 1.13 2006/02/05 23:11:17 joerg Exp $
#

DISTNAME=	mod_layout-3.2
PKGNAME=	${DISTNAME:C|mod_|ap-|}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.tangent.org/pub/apache/ \
		http://software.tangent.org/download/

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	http://software.tangent.org/
COMMENT=	Apache module to wrap static or dynamic content


APACHE_MODULE_NAME=	mod_layout.so

LAYOUT_DIR=	${PREFIX}/share/httpd/htdocs/manual/mod/mod_layout

post-install:
	${INSTALL_DATA_DIR} ${LAYOUT_DIR}
	${INSTALL_DATA} ${WRKSRC}/faq.html ${LAYOUT_DIR}
	${INSTALL_DATA_DIR} ${LAYOUT_DIR}/directives
	cd ${WRKSRC}/directives && ${PAX} -rw . ${LAYOUT_DIR}/directives

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
