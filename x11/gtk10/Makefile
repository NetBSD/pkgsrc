# $NetBSD: Makefile,v 1.2 1998/10/04 18:39:13 tron Exp $

DISTNAME=	gtk+-1.0.4
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.gimp.org/pub/gtk/v1.0/ \
		ftp://infosoc.uni-koeln.de/pub/ftp.gimp.org/pub/gtk/v1.0/ \
		ftp://ftp.flirble.org/pub/X/gimp/pub/gtk/v1.0/

MAINTAINER=	bsieker@techfak.uni-bielefeld.de
HOMEPAGE=	http://www.gtk.org/

CONFLICTS=	gtk+-1.0.0 gtk+-1.1 glib-1.1.2 glib-1.1.3

USE_LIBTOOL=	yes
USE_X11=	yes

GNU_CONFIGURE=  yes
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}"

CFLAGS=		-pipe -O2
INFO_FILES=	gdk.info glib.info gtk.info

.include "../../mk/bsd.pkg.mk"
