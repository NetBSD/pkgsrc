# $NetBSD: Makefile,v 1.1 2015/02/01 08:11:20 taca Exp $

MODNAME=	apcu
PECL_VERSION=	4.0.7
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

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
