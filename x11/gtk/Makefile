# $NetBSD: Makefile,v 1.26 1999/01/30 23:18:56 agc Exp $

DISTNAME=	gtk+-1.1.12
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.gtk.org/pub/gtk/v1.1/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.1/ \
		http://www.ameth.org/gimp/pub/gtk/v1.1/ \
		ftp://infosoc.uni-koeln.de/pub/ftp.gimp.org/pub/gtk/v1.1/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gtk.org/

DEPENDS+=	gettext-0.10.35:../../devel/gettext
DEPENDS+=	glib-1.1.12:../../devel/glib
BUILD_DEPENDS=	${LOCALBASE}/bin/perl:../../lang/perl5

CONFLICTS=	gtk+-*

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
