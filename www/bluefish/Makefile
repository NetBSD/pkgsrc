# $NetBSD: Makefile,v 1.46 2004/10/03 00:18:25 tv Exp $
#

DISTNAME=	bluefish-0.13
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://pkedu.fbt.eitn.wau.nl/~olivier/downloads/	\
		ftp://bluefish.advancecreations.com/bluefish/downloads/ \
		http://bluefish.mrball.net/downloads/			\
		ftp://ftp.ratisbona.com/pub/bluefish/downloads/		\
		http://bluefish.shellhung.org/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wulf@ping.net.au
HOMEPAGE=	http://bluefish.openoffice.nl/
COMMENT=	GTK HTML editor for the experienced web designer

DEPENDS+=		weblint-[0-9]*:../../www/weblint
BUILD_USES_MSGFMT=	YES

USE_BUILDLINK3=		yes
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	# defined
USE_X11=		# defined
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		# defined

CONFIGURE_ARGS+=	--with-autocomplet
CONFIGURE_ARGS+=	--with-icon-path=${PREFIX}/share/pixmaps
CONFIGURE_ARGS+=	--with-gnome2-menu=${PREFIX}/share/applications

.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
