# $NetBSD: Makefile,v 1.3 2019/11/04 22:09:51 rillig Exp $

DISTNAME=		mod_encoding-20021209
PKGNAME=		${APACHE_PKG_PREFIX}-${DISTNAME:S/mod_//}
CATEGORIES=		www
MASTER_SITES=		http://webdav.todo.gr.jp/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://webdav.todo.gr.jp/
COMMENT=		Non-ascii filename interoperability
#LICENSE=		# Pending change from Internet Initiative Japan, Inc.

APACHE_MODULE_NAME=	${DISTNAME:C/-.*//}.la
GNU_CONFIGURE=		yes

DOC_DIR=		share/doc/${DISTNAME:C/-.*//}
INSTALLATION_DIRS+=	lib/httpd ${DOC_DIR}
PLIST_SUBST+=		DOC_DIR=${DOC_DIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/README.JP ${DESTDIR}${PREFIX}/${DOC_DIR}

.include "../../mk/apache.module.mk"
.include "../../mk/bsd.pkg.mk"
