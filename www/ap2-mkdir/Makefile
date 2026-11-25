# $NetBSD: Makefile,v 1.5 2026/11/25 16:14:12 wiz Exp $

DISTNAME=		mod_mkdir-0.4
EXTRACT_SUFX=		.tgz
PKGNAME=		ap24-${DISTNAME:S/mod_//}
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.espci.fr/pub/mod_mkdir/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Home directory autocreation module
LICENSE=		original-bsd

APACHE_MODULE_NAME=	${DISTNAME:C/-.*//}.la

DOC_DIR=		share/doc/${DISTNAME:C/-.*//}
INSTALLATION_DIRS+=	lib/httpd ${DOC_DIR}
PLIST_SUBST+=		DOC_DIR=${DOC_DIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/${DOC_DIR}

.include "../../mk/apache.module.mk"
.include "../../mk/bsd.pkg.mk"
