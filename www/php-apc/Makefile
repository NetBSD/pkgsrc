# $NetBSD: Makefile,v 1.10 2010/03/15 16:46:00 taca Exp $

MODNAME=	apc
PECL_VERSION=	3.1.2
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
