# $NetBSD: Makefile,v 1.13 1998/07/19 20:57:47 tv Exp $

DISTNAME=	gtk+-1.0.4
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.gimp.org/pub/gtk/v1.0/ \
		ftp://infosoc.uni-koeln.de/pub/ftp.gimp.org/pub/gtk/v1.0/ \
		ftp://ftp.flirble.org/pub/X/gimp/pub/gtk/v1.0/

MAINTAINER=	bsieker@techfak.uni-bielefeld.de

BUILD_DEPENDS=	${LOCALBASE}/bin/libtool:../../devel/libtool

CONFLICTS=	gtk+-1.0.0

USE_X11=	yes

GNU_CONFIGURE=  yes
CONFIGURE_ENV=	LIBTOOL=${PREFIX}/bin/libtool \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}"

CFLAGS=		-pipe -O2
INFO_FILES=	gdk.info glib.info gtk.info

.include "../../mk/bsd.pkg.mk"
