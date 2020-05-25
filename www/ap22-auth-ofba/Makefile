# $NetBSD: Makefile,v 1.4 2020/05/25 05:55:14 rillig Exp $

DISTNAME=	mod_auth_ofba-0.6
PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME:S/mod_//:S/_/-/g}
CATEGORIES=	www
MASTER_SITES=	https://ftp.espci.fr/pub/mod_auth_ofba/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ftp.espci.fr/pub/mod_auth_ofba/README.txt
COMMENT=	MS-OFBA authentication
LICENSE=	original-bsd

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
USE_APR=		yes
GNU_CONFIGURE_APXS2=	no

.include "../../mk/apache.mk"

APACHE_MODULE_NAME=	mod_auth_ofba.${MODULE_EXT}
MODULE_EXT=		la

DOC_DIR=		share/doc/mod_auth_ofba
INSTALLATION_DIRS+=	sbin ${DOC_DIR}

do-install:
	cd ${WRKSRC} && ${MAKE} install DESTDIR=${DESTDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README ${DESTDIR}${PREFIX}/${DOC_DIR}/

.include "../../mk/apache.module.mk"
.include "../../mk/bsd.pkg.mk"
