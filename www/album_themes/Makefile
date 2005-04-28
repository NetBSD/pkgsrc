# $NetBSD $
#

DISTNAME=	album_themes
CATEGORIES=	www
MASTER_SITES=	http://marginalhacks.com/bin/

MAINTAINER=	augustss@NetBSD.org
HOMEPAGE=	http://marginalhacks.com/Hacks/album/Download.html
COMMENT=	Themes for the album generator

DEPENDS+=	album-*:../../www/album

NO_CONFIGURE=	# defined
NO_BUILD=	# defined
EXTRACT_ONLY=	# defined

A_DATADIR=	share/Album
A_HTTPDIR=	share/httpd/htdocs/Album

PLIST_SRC=		${WRKDIR}/PLIST

MESSAGE_SUBST= A_DATADIR=${A_DATADIR} A_HTTPDIR=${A_HTTPDIR}

# dynamic PLIST generation
pre-install:
	@${RM} -f ${PLIST_SRC}
	@${TAR} -tvzf ${DISTDIR}/${DISTFILES} | \
	 ${SED} -n -e 's,^-.* ,${A_DATADIR}/,p' >> ${PLIST_SRC}
	@${TAR} -tvzf ${DISTDIR}/${DISTFILES} | \
	 ${SED} -n -e 's,^d.* ,@dirrm ${A_DATADIR}/,p' | ${SORT} -r >> ${PLIST_SRC}
	@${ECHO} "@dirrm ${A_DATADIR}/Themes" >> ${PLIST_SRC}
	@${ECHO} "@dirrm ${A_DATADIR}" >> ${PLIST_SRC}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${A_DATADIR}
	cd ${PREFIX}/${A_DATADIR}; \
	${TAR} -xzf ${DISTDIR}/${DISTFILES}

.include "../../mk/bsd.pkg.mk"
