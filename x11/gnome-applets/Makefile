# $NetBSD: Makefile,v 1.8 2000/10/18 00:07:41 jlam Exp $
#

DISTNAME=		gnome-applets-1.2.2
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-applets/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/

BUILD_DEPENDS+=		autoreconf:../../devel/autoconf
BUILD_DEPENDS+=		automake:../../devel/automake
DEPENDS+=		gnome-core>=1.2.1:../../x11/gnome-core
DEPENDS+=		libgtop>=1.0.0:../../devel/libgtop

USE_GMAKE=		# defined
USE_X11BASE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=		-I${LOCALBASE}/include

AUTOGEN_ENV=		NOCONFIGURE=1
AUTOGEN_ENV+=		srcdir=${WRKSRC}

pre-configure:
	cd ${WRKSRC} && ${MV} -f aclocal.m4 acinclude.m4
	cd ${WRKSRC} && ${SETENV} ${AUTOGEN_ENV} ${SH} macros/autogen.sh

post-install:
	${RMDIR} ${PREFIX}/share/gnome/help/cpuload_applet/C/stylesheet-images
	${RMDIR} ${PREFIX}/share/gnome/help/cpuload_applet/it/stylesheet-images
	${RMDIR} ${PREFIX}/share/gnome/help/loadavg_applet/C/stylesheet-images
	${RMDIR} ${PREFIX}/share/gnome/help/loadavg_applet/it/stylesheet-images
	${RMDIR} ${PREFIX}/share/gnome/help/memload_applet/C/stylesheet-images
	${RMDIR} ${PREFIX}/share/gnome/help/memload_applet/it/stylesheet-images
	${RMDIR} ${PREFIX}/share/gnome/help/netload_applet/C/stylesheet-images
	${RMDIR} ${PREFIX}/share/gnome/help/netload_applet/it/stylesheet-images
	${RMDIR} ${PREFIX}/share/gnome/help/swapload_applet/C/stylesheet-images
	${RMDIR} ${PREFIX}/share/gnome/help/swapload_applet/it/stylesheet-images

.include "../../mk/bsd.pkg.mk"
