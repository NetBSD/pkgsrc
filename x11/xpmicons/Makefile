# $NetBSD: Makefile,v 1.3 2000/05/21 00:48:32 wiz Exp $

DISTNAME=	xpmicons-1.0
CATEGORIES=	x11
MASTER_SITES=	http://www.plig.org/xwinman/ \
		ftp://ftp.cit.gu.edu.au/pub/AIcons/ \
		${MASTER_SITE_SUNSITE:=X11/icons/} \
		http://the-labs.com/AfterStep/ \
		http://nether.tky.hut.fi/iconstore/
DISTFILES=	icons.tar.gz KDEicons.tgz \
		3d_pixmaps_V1.21.tar.gz StarOffice3.1-icons.tar.gz \
		eicons-1.0.tar.gz kdeicons.tgz wm-icons-0.2.6.tar.gz \
		next-icon_at_gun.com-3Q94-xpm.tar.gz isiconpack4.tgz \
		kiwi_icons.tgz gimp_icons.tgz x11amp_icons.tgz \
		avi-windows-icons.tgz oliphant-neon.tgz

MAINTAINER=	root@garbled.net

DIST_SUBDIR=	icons
WRKSRC=		${WRKDIR}
USE_X11BASE=	yes
NO_BUILD=	yes

post-extract:
	${FIND} ${WRKSRC} -type d -name .xvpics -exec ${RM} -rf {} \; -prune

do-install:
	${FIND} ${WRKSRC} -name \*.xpm -exec ${INSTALL_DATA} {} ${PREFIX}/include/X11/pixmaps \;
	${FIND} ${WRKSRC} -name \*.xbm -exec ${INSTALL_DATA} {} ${PREFIX}/include/X11/bitmaps \;

.include "../../mk/bsd.pkg.mk"
