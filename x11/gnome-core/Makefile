# $NetBSD: Makefile,v 1.32 1999/11/14 18:57:30 tron Exp $

DISTNAME=		gnome-core-1.0.53
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=gnome-1.0.53/sources/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnome.org/

DEPENDS+=		libghttp-*:../../www/libghttp
DEPENDS+=		gnome-libs-*:../../x11/gnome-libs

GNU_CONFIGURE=		yes
USE_X11BASE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes

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

pre-configure:
	@${MKDIR} ${WRKDIR}/sys
	@${LN} -s /usr/include/soundcard.h ${WRKDIR}/sys

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD")
.if (${MACHINE_ARCH} == arm32) || (${MACHINE_ARCH} == i386) || \
   (${MACHINE_ARCH} == m68k)
DEPENDS+=		libgtop-*:../../devel/libgtop
.endif

.if exists(/usr/include/machine/apmvar.h)
CPPFLAGS+=		-D__NetBSD_APM__
.endif
.endif

.include "../../mk/bsd.pkg.mk"
