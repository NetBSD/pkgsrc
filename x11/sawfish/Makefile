# $NetBSD: Makefile,v 1.3 2000/10/27 08:07:46 jlam Exp $
#

DISTNAME=		sawfish-${SF_VERS}
SF_VERS=		0.32
CATEGORIES=		x11 gnome
MASTER_SITES=		ftp://mirror.capital-internet.net/pub/sawmill/sawfish/ \
			ftp://eprom.dhs.org/pub/mirrors/sawmill/ \
			http://ftp.fi.muni.cz/pub/linux/sawmill/ \
			ftp://ftp.dcs.warwick.ac.uk/people/John.Harper/ \
			ftp://ftp.du.se/pub/mirrors/sawfish/ \
			ftp://sawmill.sourceforge.net/pub/sawmill/

MAINTAINER=		danw@netbsd.org
HOMEPAGE=		http://sawmill.sourceforge.net/

DEPENDS+=		librep>=0.13:../../lang/librep
DEPENDS+=		rep-gtk>=0.14:../../x11/rep-gtk
DEPENDS+=		imlib>=1.8.2:../../graphics/imlib
DEPENDS+=		control-center-*:../../x11/controlcenter

USE_X11BASE=		# defined
USE_GMAKE=		# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ENV+=		LOCALEBASE=${LOCALEBASE}
MAKE_ENV+=		LOCALEBASE=${LOCALEBASE}

PLIST_SUBST+=		SF_VERS=${SF_VERS}
PLIST_SUBST+=		LOCALEBASE=${LOCALEBASE}

.include "../../mk/bsd.prefs.mk"

# The directory in which locale files are found is:
#
#	${PREFIX}/${LOCALEBASE}/locale/<lang>/LC_MESSAGES
#
.if ${OPSYS} == "SunOS"
LOCALEBASE=		lib
.else
LOCALEBASE=		share
.endif

post-install:
	${MKDIR} ${PREFIX}/share/sawfish/themes
	${TOUCH} ${PREFIX}/share/sawfish/themes/.directory
	${MKDIR} ${PREFIX}/share/sawfish/sounds
	${TOUCH} ${PREFIX}/share/sawfish/sounds/.directory

.include "../../mk/bsd.pkg.mk"
