# $NetBSD: Makefile,v 1.29 2009/12/10 20:34:44 abs Exp $

DISTNAME=		xview3.2p1-X11R6
PKGNAME=		xview-config-3.2.1
PKGREVISION=		6
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		OpenLook Toolkit config files

PKG_DESTDIR_SUPPORT=	user-destdir

LICENSE=                sun-openlook-license
NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

EXTRACT_ELEMENTS=	${DISTNAME}/config

WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}
USE_IMAKE=		yes

post-extract:
	${CHMOD} -R go+rX ${WRKDIR}

.include "../../mk/bsd.pkg.mk"
