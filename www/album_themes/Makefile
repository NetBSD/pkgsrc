# $NetBSD: Makefile,v 1.13 2009/06/14 22:58:10 joerg Exp $
#

DISTNAME=	album_themes
PKGNAME=	album_themes-20050507
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://marginalhacks.com/bin/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://marginalhacks.com/Hacks/album/Download.html
COMMENT=	Themes for the album generator

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	album-[0-9]*:../../www/album

NO_CONFIGURE=	YES
NO_BUILD=	YES
EXTRACT_ONLY=	# none

USE_TOOLS+=	tar

A_DATADIR=	share/Album
A_HTTPDIR=	share/httpd/htdocs/Album

PLIST_SRC=		${WRKDIR}/PLIST

MESSAGE_SUBST= A_DATADIR=${A_DATADIR} A_HTTPDIR=${A_HTTPDIR}

INSTALLATION_DIRS=	${A_DATADIR}

# dynamic PLIST generation
pre-install:
	@${RM} -f ${PLIST_SRC}
	@${TAR} -tvzf ${DISTDIR}/${DISTFILES} | \
	 ${SED} -n -e 's,^-.* ,${A_DATADIR}/,p' >> ${PLIST_SRC}

do-install:
	cd ${DESTDIR}${PREFIX}/${A_DATADIR}; \
	${TAR} -xzf ${DISTDIR}/${DISTFILES}

.include "../../mk/bsd.pkg.mk"
