# $NetBSD: Makefile,v 1.22 1999/08/15 14:58:59 tron Exp $
#

DISTNAME=		gnome-core-1.0.7
CATEGORIES=		x11 gnome
MASTER_SITES=		ftp://ftp.gnome.org/pub/GNOME/gnome-1.0/sources/ \
			ftp://ftp.sunet.se/pub/X11/GNOME/gnome-1.0/sources/ \
			ftp://ftp.informatik.uni-bonn.de/pub/os/unix/gnome/gnome-1.0/sources/

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnome.org/

DEPENDS+=		esound-0.2.8:../../audio/esound
DEPENDS+=		gnome-libs-1.0.10:../../x11/gnome-libs
# "libgtop" packages is broken at the moment.
#DEPENDS+=		libgtop-1.0.1:../../devel/libgtop

NOT_FOR_PLATFORM=	*-*-alpha	# problems with gtk

GNU_CONFIGURE=		yes
USE_X11BASE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes

LOCALSTATEDIR=		/var/gnome

CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR} \
			--with-glib-prefix=${LOCALBASE}
CPPFLAGS=		-I${LOCALBASE}/include -I${WRKDIR}
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE} X11BASE=${X11BASE} \
			CPPFLAGS="${CPPFLAGS}"

pre-configure:
	@${MKDIR} ${WRKDIR}/sys
	@${LN} -s /usr/include/soundcard.h ${WRKDIR}/sys

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD") && exists(/usr/include/machine/apmvar.h)
CPPFLAGS+=		-D__NetBSD_APM__
.endif

.include "../../mk/bsd.pkg.mk"
