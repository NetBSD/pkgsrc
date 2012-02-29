# $NetBSD: Makefile,v 1.31 2012/02/29 13:13:14 hans Exp $

DISTNAME=		xview3.2p1-X11R6
PKGNAME=		xview-config-3.2.1
PKGREVISION=		6
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_LOCAL}

OWNER=			dholland@NetBSD.org
COMMENT=		OpenLook Toolkit config files
LICENSE=		sun-openlook-license

PKG_DESTDIR_SUPPORT=	user-destdir

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

EXTRACT_ELEMENTS=	${DISTNAME}/config

WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}
USE_IMAKE=		yes

post-extract:
	${CHMOD} -R go+rX ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
