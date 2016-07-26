# $NetBSD: Makefile,v 1.3 2016/07/26 09:22:40 jdolecek Exp $

MODNAME=	apcu
PECL_VERSION=	5.1.5
CATEGORIES+=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	APCu - APC User Cache
LICENSE=	php

CONFIGURE_ARGS+=	--enable-${MODNAME}

PLIST_SRC+=		${.CURDIR}/PLIST.extras
PLIST_SUBST+=		PKGBASE=${PKGBASE:Q}

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${DOCDIR}
	cd ${WRKSRC} && ${MAKE} INSTALL_ROOT="${DESTDIR}" install-headers

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
