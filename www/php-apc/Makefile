# $NetBSD: Makefile,v 1.11 2010/03/16 13:57:27 taca Exp $

MODNAME=	apc
PECL_VERSION=	3.1.3p1
CATEGORIES+=	sysutils
COMMENT=	Alternative PHP Cache

MAINTAINER=		pkgsrc-users@NetBSD.org

CONFLICTS=		php-apc-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--enable-${MODNAME}
WRKSRC=			${WRKDIR}/APC-${PECL_VERSION}

PLIST_SRC+=		${.CURDIR}/PLIST.extras
PLIST_SUBST+=		PKGBASE=${PKGBASE:Q}

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${DOCDIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
