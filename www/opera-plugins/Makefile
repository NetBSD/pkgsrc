# $NetBSD: Makefile,v 1.4 2003/12/16 13:28:40 tron Exp $

DISTNAME=	opera-plugins-1.0
CATEGORIES=	www
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.opera.com/
COMMENT=	Plugins for the Opera browser

DEPENDS+=	opera>=5.999.1:../opera7
DEPENDS+=	ns-flash>=5.0.47:../../graphics/ns-flash
DEPENDS+=	suse_openmotif>=7.3:../../emulators/suse_openmotif

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_BUILD=	YES
PLIST_SRC=	${WRKDIR}/PLIST

EMULSUBDIR=	emul/linux
EMULDIR=	${PREFIX}/${EMULSUBDIR}

PLUGIN_DIR=	${PREFIX}/lib/netscape/plugins
# The FlashPlayer plugin is the only one I got completely working so far.
# Sun's Java Plugin fails, Acrobat and RealPlayer are not recognized by
# name. If you get more plugins working add them (including dependences)
# and bump the version number.
PLUGINS=	libflashplayer.so

do-install:
		${RM} -f ${PLIST_SRC}
		${TOUCH} ${PLIST_SRC}
		for FILE in ${PLUGINS}; do 				\
		  ${LN} -fs ${PLUGIN_DIR}/$$FILE			\
		    ${EMULDIR}/usr/lib/opera/plugins/$$FILE;		\
		  ${ECHO} ${EMULSUBDIR}/usr/lib/opera/plugins/$$FILE	\
		    >>${PLIST_SRC};					\
		done

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
