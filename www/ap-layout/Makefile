# $NetBSD: Makefile,v 1.21 2012/10/28 06:30:04 asau Exp $
#

DISTNAME=	mod_layout-3.2
PKGNAME=	${DISTNAME:C|mod_|ap13-|}
CATEGORIES=	www
MASTER_SITES=	http://download.tangent.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tangent.org/
COMMENT=	Apache module to wrap static or dynamic content

USE_TOOLS+=	pax

CONFLICTS=	ap-layout-[0-9]*

APACHE_MODULE_NAME=	mod_layout.so

LAYOUT_DIR=	${PREFIX}/share/httpd/htdocs/manual/mod/mod_layout

INSTALLATION_DIRS+=	${LAYOUT_DIR}/directives

post-install:
	${INSTALL_DATA} ${WRKSRC}/faq.html ${DESTDIR}${LAYOUT_DIR}
	cd ${WRKSRC}/directives && pax -rw . ${DESTDIR}${LAYOUT_DIR}/directives

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
