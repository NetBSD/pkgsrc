# $NetBSD: Makefile,v 1.5 2000/06/25 17:25:03 rh Exp $
#

DISTNAME=	gnome-applets-1.2.1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/gnome-applets/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	gnome-core>=1.2.1:../../x11/gnome-core
DEPENDS+=	libgtop-*:../../devel/libgtop

USE_GMAKE=	yes
USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"

.if exists(/usr/include/machine/apmvar.h)
CPPFLAGS+=	-D__NetBSD_APM__
.endif

.include "../../mk/bsd.pkg.mk"
