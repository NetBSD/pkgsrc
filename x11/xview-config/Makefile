# $NetBSD: Makefile,v 1.30 2011/08/11 05:49:29 dholland Exp $

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
	${CHMOD} -R go+rX ${WRKDIR}

.include "../../mk/bsd.pkg.mk"
