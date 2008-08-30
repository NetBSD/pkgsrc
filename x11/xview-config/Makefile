# $NetBSD: Makefile,v 1.27 2008/08/30 19:52:50 dholland Exp $

DISTNAME=		xview3.2p1-X11R6
PKGNAME=		xview-config-3.2.1
PKGREVISION=		4
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		OpenLook Toolkit config files

PKG_DESTDIR_SUPPORT=	user-destdir

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

EXTRACT_ELEMENTS=	${DISTNAME}/config

WRKSRC=		${WRKDIR}/${EXTRACT_ELEMENTS}
USE_IMAKE=		yes

post-extract:
	@${CHMOD} -R go+rX ${WRKDIR}

.include "../../mk/bsd.pkg.mk"
