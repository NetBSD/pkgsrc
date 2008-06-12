# $NetBSD: Makefile,v 1.7 2008/06/12 02:14:56 joerg Exp $

MODNAME=	apc
PECL_VERSION=	3.0.16
CATEGORIES+=	sysutils
COMMENT=	Alternative PHP Cache

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-apc-[0-9]*

MAINTAINER=	pkgsrc-users@NetBSD.org

CONFIGURE_ARGS+=	--enable-${MODNAME}
WRKSRC=		${WRKDIR}/APC-${PECL_VERSION}

PLIST_SRC+=		${.CURDIR}/PLIST.extras
PLIST_SUBST+=		PKGBASE=${PKGBASE:Q}

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${DOCDIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
