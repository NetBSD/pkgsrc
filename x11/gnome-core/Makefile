# $NetBSD: Makefile,v 1.15 1999/05/02 15:52:57 tron Exp $
#

DISTNAME=	gnome-core-1.0.5
CATEGORIES=	x11 gnome
MASTER_SITES=	ftp://ftp.gnome.org/pub/GNOME/gnome-1.0/sources/ \
		ftp://ftp.jimpick.com/pub/mirrors/gnome/gnome-1.0/sources/ \
		ftp://ftp.informatik.uni-bonn.de/pub/os/unix/gnome/gnome-1.0/sources/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	esound-0.2.8:../../audio/esound
DEPENDS+=	gnome-libs-1.0.9:../../x11/gnome-libs
# "libgtop" packages is broken at the moment.
#DEPENDS+=	libgtop-1.0.1:../../devel/libgtop

NOT_FOR_ARCHS=	alpha	# problems with gtk

GNU_CONFIGURE=	yes
USE_X11BASE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

LOCALSTATEDIR=	/var/gnome

CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR} \
			--with-glib-prefix=${LOCALBASE}
CONFIGURE_ENV+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
			LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

.include "../../mk/bsd.pkg.mk"
