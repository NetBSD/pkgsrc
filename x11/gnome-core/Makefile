# $NetBSD: Makefile,v 1.30 1999/10/23 11:01:43 tron Exp $

DISTNAME=		gnome-core-1.0.53
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=gnome-1.0.53/sources/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnome.org/

DEPENDS+=		esound-*:../../audio/esound
DEPENDS+=		libghttp-*:../../www/libghttp
DEPENDS+=		gnome-libs-*:../../x11/gnome-libs
DEPENDS+=		libgtop-*:../../devel/libgtop

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

.if (${OPSYS} == "NetBSD") && exists(/usr/include/machine/apmvar.h)
CPPFLAGS+=		-D__NetBSD_APM__
.endif

.include "../../mk/bsd.pkg.mk"
