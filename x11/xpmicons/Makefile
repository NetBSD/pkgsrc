# $NetBSD: Makefile,v 1.13 2006/09/02 19:30:45 rillig Exp $

DISTNAME=	xpmicons-1.0
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://www.plig.org/xwinman/ \
		ftp://ftp.cit.gu.edu.au/pub/AIcons/ \
		${MASTER_SITE_SUNSITE:=X11/icons/} \
		http://the-labs.com/AfterStep/
DISTFILES=	icons.tar.gz KDEicons.tgz \
		3d_pixmaps_V1.21.tar.gz StarOffice3.1-icons.tar.gz \
		eicons-1.0.tar.gz kdeicons.tgz wm-icons-0.2.6.tar.gz \
		next-icon_at_gun.com-3Q94-xpm.tar.gz isiconpack4.tgz \
		kiwi_icons.tgz gimp_icons.tgz x11amp_icons.tgz \
		avi-windows-icons.tgz oliphant-neon.tgz

MAINTAINER=	root@garbled.net
COMMENT=	Huge collection of icons for any windowmanager

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	icons
USE_X11BASE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	include/X11/bitmaps include/X11/pixmaps

.include "../../mk/x11.buildlink3.mk"

post-extract:
	find ${WRKSRC} -type d -name .xvpics -exec rm -rf {} \; -prune

do-install:
	find ${WRKSRC} -name \*.xpm -exec ${INSTALL_DATA} {} ${PREFIX}/include/X11/pixmaps \;
	find ${WRKSRC} -name \*.xbm -exec ${INSTALL_DATA} {} ${PREFIX}/include/X11/bitmaps \;

.include "../../mk/bsd.pkg.mk"
