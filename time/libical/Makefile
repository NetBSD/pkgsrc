# $NetBSD: Makefile,v 1.2 2009/03/19 11:57:48 drochner Exp $
#

DISTNAME=	libical-0.43
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

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
# zone.tab file in /usr/share/zoneinfo
DEPENDS+= zonetab-[0-9]*:../../time/zonetab
.endif

.include "../../mk/bsd.pkg.mk"
