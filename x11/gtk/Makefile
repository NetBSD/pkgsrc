# $NetBSD: Makefile,v 1.18 1998/10/04 18:27:47 tron Exp $

DISTNAME=	gtk+-1.1.2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.gtk.org/pub/gtk/v1.1/ \
		ftp://infosoc.uni-koeln.de/pub/ftp.gimp.org/pub/gtk/v1.1/ \
		ftp://ftp.flirble.org/pub/X/gimp/pub/gtk/v1.1/

MAINTAINER=	bsieker@techfak.uni-bielefeld.de
HOMEPAGE=	http://www.gtk.org/

DEPENDS+=	glib-1.1.3:../../devel/glib

CONFLICTS=	gtk+-1.0.0 gtk+-1.0.4 gtk+-1.1.1

USE_LIBTOOL=	yes
USE_X11=	yes

GNU_CONFIGURE=  yes
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}"

CFLAGS=		-pipe -O2
INFO_FILES=	gdk.info gtk.info

.include "../../mk/bsd.pkg.mk"
