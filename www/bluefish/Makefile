# $NetBSD: Makefile,v 1.33 2003/12/03 03:50:15 xtraeme Exp $
#

DISTNAME=	bluefish-0.12
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

DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs
DEPENDS+=		weblint-[0-9]*:../../www/weblint
BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2=		# defined
USE_PKGLOCALEDIR=	# defined
USE_X11=		# defined
USE_GMAKE=		# defined
GNU_CONFIGURE=		# defined

CONFIGURE_ARGS+=	--with-autocomplet
CONFIGURE_ARGS+=	--with-icon-path=${PREFIX}/share/pixmaps
CONFIGURE_ARGS+=	--with-gnome2-menu=${PREFIX}/share/applications	

.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../devel/pcre/buildlink2.mk"
.include "../../textproc/aspell/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
