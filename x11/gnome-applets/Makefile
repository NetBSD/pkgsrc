# $NetBSD: Makefile,v 1.4 2000/06/25 12:50:24 wiz Exp $
#

DISTNAME=	gnome-applets-1.2.0
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/gnome-applets/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	gnome-core-*:../../x11/gnome-core
DEPENDS+=	libgtop-*:../../devel/libgtop

USE_GMAKE=	yes
USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"

.if exists(/usr/include/machine/apmvar.h)
CPPFLAGS+=	-D__NetBSD_APM__
.endif

.include "../../mk/bsd.pkg.mk"
