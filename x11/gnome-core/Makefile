# $NetBSD: Makefile,v 1.46 2000/06/25 17:22:52 rh Exp $

DISTNAME=		gnome-core-1.2.1
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-core/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnome.org/

DEPENDS+=		control-center>=1.2.0:../../x11/controlcenter
DEPENDS+=		gdk-pixbuf>=0.7.0:../../graphics/gdk-pixbuf
DEPENDS+=		libghttp>=1.0.4:../../www/libghttp
DEPENDS+=		libxml-*:../../textproc/libxml

GNU_CONFIGURE=		# defined
USE_X11BASE=		# defined
USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

LOCALSTATEDIR=		/var/gnome

ESD_CONFIG=		${LOCALBASE}/bin/esd-config
ESD_CFLAGS=		`${ESD_CONFIG} --cflags`
ESD_LIBS=		`${ESD_CONFIG} --libs`

CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR}
CPPFLAGS=		-I${LOCALBASE}/include -I${WRKDIR}
CONFIGURE_ENV+=		ESD_CFLAGS="${ESD_CFLAGS}" \
			ESD_CONFIG="${ESD_CONFIG}" \
			ESD_LIBS="${ESD_LIBS}" \
			LOCALBASE=${LOCALBASE} X11BASE=${X11BASE} \
			CPPFLAGS="${CPPFLAGS}"

PLIST_SRC=		${WRKDIR}/PLIST

pre-configure:
	@${MKDIR} ${WRKDIR}/sys
	@${LN} -fs /usr/include/soundcard.h ${WRKDIR}/sys

post-install:
	@if [ -x ${PREFIX}/bin/cpumemusage_applet ]; then \
	  ${CP} ${PKGDIR}/PLIST.${OPSYS} ${PLIST_SRC}; \
	else \
	  ${EGREP} -v '/((cpumem|disk)usage|(cpu|mem|multi|swap)load)_applet' \
		< ${PKGDIR}/PLIST.${OPSYS} > ${PLIST_SRC}; \
	fi

.include "../../mk/bsd.pkg.mk"
