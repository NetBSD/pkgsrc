# $NetBSD: Makefile,v 1.2 2014/01/27 18:41:15 wiz Exp $

DISTNAME=	elementary-icon-theme-3.0
CATEGORIES=	graphics
MASTER_SITES=	https://launchpad.net/elementaryicons/3.x/3.0/+download/
DISTFILES=	elementary.tar.gz

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://elementaryos.org/docs/packaging/themes/elementary-icons
COMMENT=	Simple and appealing Tango-styled icon theme
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/elementary
NO_BUILD=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	pax

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/icons
	cd ${WRKSRC} && pax -rw -pe . ${DESTDIR}${PREFIX}/share/icons/

.include "../../mk/bsd.pkg.mk"
