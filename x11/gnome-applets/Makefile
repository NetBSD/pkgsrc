# $NetBSD: Makefile,v 1.1.1.1 2000/06/02 13:08:29 drochner Exp $
#

DISTNAME=	gnome-applets-1.2.0
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/gnome-applets/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	gnome-core-*:../../x11/gnome-core

USE_X11BASE=	yes
GNU_CONFIGURE=	YES
USE_GMAKE=	yes

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
