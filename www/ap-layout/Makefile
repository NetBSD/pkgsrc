# $NetBSD: Makefile,v 1.18 2009/06/06 22:37:22 zafer Exp $
#

DISTNAME=	mod_layout-3.2
PKGNAME=	${DISTNAME:C|mod_|ap13-|}
CATEGORIES=	www
MASTER_SITES=	http://download.tangent.org/

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	http://tangent.org/
COMMENT=	Apache module to wrap static or dynamic content

USE_TOOLS+=	pax

CONFLICTS=	ap-layout-[0-9]*

APACHE_MODULE_NAME=	mod_layout.so

LAYOUT_DIR=	${PREFIX}/share/httpd/htdocs/manual/mod/mod_layout

post-install:
	${INSTALL_DATA_DIR} ${LAYOUT_DIR}
	${INSTALL_DATA} ${WRKSRC}/faq.html ${LAYOUT_DIR}
	${INSTALL_DATA_DIR} ${LAYOUT_DIR}/directives
	cd ${WRKSRC}/directives && pax -rw . ${LAYOUT_DIR}/directives

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
