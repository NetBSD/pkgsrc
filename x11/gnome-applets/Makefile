# $NetBSD: Makefile,v 1.2 2000/06/03 17:31:44 rh Exp $
#

DISTNAME=	gnome-applets-1.2.0
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/gnome-applets/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	gnome-core-*:../../x11/gnome-core

USE_GMAKE=	yes
USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD")
.if (${MACHINE_ARCH} == arm32) || (${MACHINE_ARCH} == i386) || \
   (${MACHINE_ARCH} == m68k)
DEPENDS+=	libgtop-*:../../devel/libgtop
.endif

.if exists(/usr/include/machine/apmvar.h)
CPPFLAGS+=	-D__NetBSD_APM__
.endif
.endif

.include "../../mk/bsd.pkg.mk"
