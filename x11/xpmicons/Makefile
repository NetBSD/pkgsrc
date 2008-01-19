# $NetBSD: Makefile,v 1.23 2008/01/19 09:16:26 wiz Exp $

DISTNAME=	xpmicons-1.0
PKGREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	http://www.plig.org/xwinman/
DISTFILES=	icons.tar.gz KDEicons.tgz \
		3d_pixmaps_V1.21.tar.gz StarOffice3.1-icons.tar.gz \
		eicons-1.0.tar.gz kdeicons.tgz wm-icons-0.2.6.tar.gz \
		next-icon_at_gun.com-3Q94-xpm.tar.gz isiconpack4.tgz \
		kiwi_icons.tgz gimp_icons.tgz x11amp_icons.tgz \
		avi-windows-icons.tgz oliphant-neon.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Huge collection of icons for any windowmanager

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	icons
USE_X11BASE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	include/X11/bitmaps include/X11/pixmaps

post-extract:
	find ${WRKSRC} -type d -name .xvpics -print | ${XARGS} rm -rf

do-install:
	set -e; cd ${WRKSRC}; find * -name \*.xpm -print | \
		while read f; do ${INSTALL_DATA} $$f ${PREFIX}/include/X11/pixmaps; done
	set -e; cd ${WRKSRC}; find * -name \*.xbm -print | \
		while read f; do ${INSTALL_DATA} $$f ${PREFIX}/include/X11/bitmaps; done

.include "../../mk/bsd.pkg.mk"
