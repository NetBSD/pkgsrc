# $NetBSD: Makefile,v 1.11 1998/06/20 23:17:31 tron Exp $

DISTNAME=	gtk+-1.0.4
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.gimp.org/pub/gtk/v1.0/ \
		ftp://infosoc.uni-koeln.de/pub/ftp.gimp.org/pub/gtk/v1.0/ \
		ftp://ftp.flirble.org/pub/X/gimp/pub/gtk/v1.0/

MAINTAINER=	bsieker@techfak.uni-bielefeld.de

CONFLICTS=	gtk+-1.0.0

GNU_CONFIGURE=  yes
USE_X11=	yes

CFLAGS=		-pipe -O2
INFO_FILES=	gdk.info glib.info gtk.info

.include "../../mk/bsd.pkg.mk"
