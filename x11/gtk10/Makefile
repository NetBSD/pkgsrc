# $NetBSD: Makefile,v 1.13 2001/04/27 11:43:40 tron Exp $

DISTNAME=	gtk+-1.0.6
PKGNAME=	gtk10-1.0.6
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.gtk.org/pub/gtk/v1.0/

MAINTAINER=	bsieker@techfak.uni-bielefeld.de
HOMEPAGE=	http://www.gtk.org/
COMMENT=	Gimp toolkit. Libraries for building X11 user interfaces

CONFLICTS=	gtk+-1.0.*

USE_LIBTOOL=	yes
USE_X11BASE=	yes

GNU_CONFIGURE=  yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/gtk10

CFLAGS=		-pipe -O2
INFO_FILES=	gdk10.info glib10.info gtk10.info

post-extract:
	cd ${WRKSRC}/docs && ${RM} -f ${INFO_FILES}

.include "../../mk/bsd.pkg.mk"
