# $NetBSD: Makefile,v 1.12 2025/02/08 03:58:34 taca Exp $

DISTNAME=	mod_upload-1.0
PKGNAME=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}-${DISTNAME:S/mod_//}
CATEGORIES=	www
MASTER_SITES=	https://ftp.espci.fr/pub/mod_upload/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ftp.espci.fr/pub/mod_upload/
COMMENT=	High performance file upload helper for PHP
LICENSE=	gnu-gpl-v2

APACHE_MODULE_NAME=	${DISTNAME:C/-.*//}.la

PHP_VERSIONS_INCOMPATIBLE=	56

GNU_CONFIGURE=		yes
GNU_CONFIGURE_APXS2=	no
CONFIGURE_ARGS+=	--with-apxs=${APXS}
#CONFIGURE_ARGS+=	--with-php-config=${BUILDLINK_PREFIX.php}/bin/php-config
CONFIGURE_ARGS+=	--with-php-config=${PREFIX}/bin/php-config${PHP_VER}
USE_LIBTOOL=		yes

DOC_DIR=		share/doc/${DISTNAME:C/-.*//}
INSTALLATION_DIRS+=	lib/httpd ${DOC_DIR}
PLIST_SUBST+=		DOC_DIR=${DOC_DIR}

do-build:
	cd ${WRKSRC} && ${MAKE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/${DOC_DIR}

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/apache.module.mk"
.include "../../mk/bsd.pkg.mk"
