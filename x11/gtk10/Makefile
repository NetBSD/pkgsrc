# $NetBSD: Makefile,v 1.17 2003/10/22 01:20:30 grant Exp $

DISTNAME=	gtk+-1.0.6
PKGNAME=	gtk10-1.0.6
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.gtk.org/pub/gtk/v1.0/

MAINTAINER=	bsieker@techfak.uni-bielefeld.de
HOMEPAGE=	http://www.gtk.org/
COMMENT=	The GIMP Toolkit - libraries for building X11 user interfaces

CONFLICTS=	gtk+-1.0.*

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
USE_MAKEINFO=		yes
USE_X11BASE=		yes

GNU_CONFIGURE=  yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/gtk10

INFO_FILES=	gdk10.info glib10.info gtk10.info

post-extract:
	cd ${WRKSRC}/docs && ${RM} -f ${INFO_FILES}

.include "../../mk/bsd.pkg.mk"
