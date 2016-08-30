# $NetBSD: Makefile,v 1.1 2016/08/30 12:47:49 manu Exp $

DISTNAME=		mod_mkdir-0.3
EXTRACT_SUFX=		.tgz
PKGNAME=		${APACHE_PKG_PREFIX}-${DISTNAME:S/mod_//}
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.espci.fr/pub/mod_mkdir/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Home directory autocreation module
LICENSE=		original-bsd

PKG_APACHE_ACCEPTED=	apache22 apache24

APACHE_MODULE_NAME=	${DISTNAME:C/-.*//}.la

DOC_DIR=		share/doc/${DISTNAME:C/-.*//}
INSTALLATION_DIRS+=	lib/httpd ${DOC_DIR}
PLIST_SUBST+=           DOC_DIR=${DOC_DIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/${DOC_DIR}

.include "../../mk/apache.module.mk"
.include "../../mk/bsd.pkg.mk"
