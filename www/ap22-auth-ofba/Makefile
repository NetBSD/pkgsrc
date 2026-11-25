# $NetBSD: Makefile,v 1.9 2026/11/25 17:16:35 wiz Exp $

DISTNAME=	mod_auth_ofba-0.6
PKGNAME=	ap24-${DISTNAME:S/mod_//:S/_/-/g}
CATEGORIES=	www
MASTER_SITES=	https://ftp.espci.fr/pub/mod_auth_ofba/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ftp.espci.fr/pub/mod_auth_ofba/README.txt
COMMENT=	MS-OFBA authentication
LICENSE=	original-bsd

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes
GNU_CONFIGURE_APXS2=	no

.include "../../www/apache24/buildlink3.mk"

APACHE_MODULE_NAME=	mod_auth_ofba.${MODULE_EXT}
MODULE_EXT=		la

DOC_DIR=		share/doc/mod_auth_ofba
INSTALLATION_DIRS+=	sbin ${DOC_DIR}

# ofba_session is not build by just make
post-build:
	cd ${WRKSRC} && ${GMAKE}

post-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ofba_session ${DESTDIR}${PREFIX}/sbin
	cd ${WRKSRC} && ${INSTALL_DATA} README ${DESTDIR}${PREFIX}/${DOC_DIR}/

.include "../../devel/apr/buildlink3.mk"
.include "../../devel/apr-util/buildlink3.mk"
.include "../../mk/apache.module.mk"
.include "../../mk/bsd.pkg.mk"
