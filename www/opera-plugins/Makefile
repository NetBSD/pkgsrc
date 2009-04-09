# $NetBSD: Makefile,v 1.15 2009/04/09 00:48:18 joerg Exp $

DISTNAME=	opera-plugins-1.0
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.opera.com/
COMMENT=	Plugins for the Opera browser

DEPENDS+=	opera>=5.999.1:../../www/opera
DEPENDS+=	ns-flash>=5.0.47:../../multimedia/ns-flash

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	motif
EMUL_REQD=		suse>=7.3

NO_BUILD=	YES
PLIST_SRC=	${WRKDIR}/PLIST

PLUGIN_DIR=	${PREFIX}/lib/netscape/plugins

# The FlashPlayer plugin is the only one I got completely working so far.
# Sun's Java Plugin fails, Acrobat and RealPlayer are not recognized by
# name. If you get more plugins working add them (including dependences)
# and bump the version number.
#
PLUGINS=	libflashplayer.so

INSTALLATION_DIRS=	${EMULSUBDIRSLASH}usr/lib/opera/plugins

do-install:
	${RM} -f ${PLIST_SRC}
	${TOUCH} ${PLIST_SRC}
	for FILE in ${PLUGINS}; do 					\
		${LN} -fs ${PLUGIN_DIR}/$$FILE				\
			${EMULDIR}/usr/lib/opera/plugins/$$FILE;	\
		${ECHO} ${EMULSUBDIRSLASH}usr/lib/opera/plugins/$$FILE	\
			>>${PLIST_SRC};					\
	done

.include "../../mk/bsd.pkg.mk"
