# $NetBSD: Makefile,v 1.40 2000/03/12 22:30:05 tron Exp $

DISTNAME=	gtk+-1.2.7
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.gtk.org/pub/gtk/v1.2/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.2/ \
		http://www.ameth.org/gimp/pub/gtk/v1.2/ \
		ftp://infosoc.uni-koeln.de/pub/ftp.gimp.org/pub/gtk/v1.2/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gtk.org/

DEPENDS+=	gettext-0.10.*:../../devel/gettext
DEPENDS+=	glib>=1.2.7:../../devel/glib
BUILD_DEPENDS+=	${LOCALBASE}/bin/perl:../../lang/perl5

USE_LIBTOOL=	yes
USE_X11BASE=	yes
USE_GMAKE=	yes

GNU_CONFIGURE=  yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" X_LDFLAGS="${X_LDFLAGS}"

INFO_FILES=	gdk.info gtk.info

CPPFLAGS=	-I${LOCALBASE}/include				# libintl.h
LDFLAGS=	-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib	# -lintl
PLIST_SUBST+=	LOCALBASE=${LOCALBASE}

# The following ensures that `gtk-config --libs' includes the correct linker
# flags for linking the X11 libs.
#
X_LDFLAGS=	-Wl,-R${X11BASE}/lib -L${X11BASE}/lib

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/gtk.m4 \
	  ${LOCALBASE}/share/aclocal/gtk.m4

.include "../../mk/bsd.pkg.mk"
