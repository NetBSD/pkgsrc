# $NetBSD: Makefile,v 1.18 2012/05/27 13:20:28 obache Exp $

DISTNAME=	opera-plugins-1.0
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.opera.com/
COMMENT=	Plugins for the Opera browser

DEPENDS+=	opera>=11.61:../../www/opera
DEPENDS+=	{adobe-flash-plugin-[0-9]*,ns-flash>=5.0.47}:../../multimedia/adobe-flash-plugin

PKG_DESTDIR_SUPPORT=	user-destdir

EMUL_PLATFORMS=		linux-i386
EMUL_REQD=		suse>=10.0

NO_BUILD=	YES
PLIST_SRC=	${WRKDIR}/PLIST

PLUGIN_DIR=	${PREFIX}/lib/netscape/plugins

# The FlashPlayer plugin is the only one I got completely working so far.
# Sun's Java Plugin fails, Acrobat and RealPlayer are not recognized by
# name. If you get more plugins working add them (including dependences)
# and bump the version number.
#
PLUGINS=	libflashplayer.so

INSTALLATION_DIRS=	lib/opera/plugins

do-install:
	${RM} -f ${PLIST_SRC}
	${TOUCH} ${PLIST_SRC}
	for FILE in ${PLUGINS}; do 					\
		${LN} -fs ${PLUGIN_DIR}/$$FILE				\
			${DESTDIR}${PREFIX}/lib/opera/plugins/$$FILE;	\
		${ECHO} lib/opera/plugins/$$FILE			\
			>>${PLIST_SRC};					\
	done

.include "../../mk/bsd.pkg.mk"
