# $NetBSD: Makefile,v 1.30 1999/05/02 14:24:58 tron Exp $

DISTNAME=	gtk+-1.2.2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.gtk.org/pub/gtk/v1.2/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.2/ \
		http://www.ameth.org/gimp/pub/gtk/v1.2/ \
		ftp://infosoc.uni-koeln.de/pub/ftp.gimp.org/pub/gtk/v1.2/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gtk.org/

DEPENDS+=	gettext-0.10.35:../../devel/gettext
DEPENDS+=	glib-1.2.2:../../devel/glib
BUILD_DEPENDS+=	${LOCALBASE}/bin/perl:../../lang/perl5

USE_LIBTOOL=	yes
USE_X11BASE=	yes
USE_GMAKE=	yes

GNU_CONFIGURE=  yes
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		CPPFLAGS="${CPPFLAGS}"

INFO_FILES=	gdk.info gtk.info

CFLAGS=		-pipe -O2
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include "../../mk/bsd.pkg.mk"
