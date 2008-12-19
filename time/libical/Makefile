# $NetBSD: Makefile,v 1.1.1.1 2008/12/19 21:48:05 markd Exp $
#

DISTNAME=	libical-0.42
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freeassociation/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://freeassociation.sourceforge.net/
COMMENT=	Reference implementation of the iCalendar data type and format

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	perl
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	libical.pc.in

.include "../../mk/bsd.pkg.mk"
