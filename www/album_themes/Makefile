# $NetBSD: Makefile,v 1.15 2015/01/08 05:25:29 mef Exp $
#

DISTNAME=	album_data
PKGNAME=	album_themes-20081222
CATEGORIES=	www
MASTER_SITES=	http://marginalhacks.com/bin/
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://marginalhacks.com/Hacks/album/Download.html
COMMENT=	Themes for the album generator

DEPENDS+=	album-[0-9]*:../../www/album
WRKSRC=		${WRKDIR}

NO_BUILD=	YES

USE_TOOLS+=	tar perl

A_DATADIR=	share/Album
A_HTTPDIR=	share/httpd/htdocs/Album

PLIST_SRC=		${WRKDIR}/PLIST

MESSAGE_SUBST= A_DATADIR=${A_DATADIR} A_HTTPDIR=${A_HTTPDIR}

INSTALLATION_DIRS=	${A_DATADIR}

EXTRACT_ELEMENTS=	lang/banner
EXTRACT_ELEMENTS+=	plugins/captions/exif/exiftool.pl
EXTRACT_ELEMENTS+=	plugins/captions/exif/p
REPLACE_PERL=		${EXTRACT_ELEMENTS}

# To activate REPLACE_PERL, not by NO_CONFIGURE= yes, but:
do-configure:
	${DO_NADA}
# dynamic PLIST generation
pre-install:
	${RM} -f ${PLIST_SRC}
	${TAR} -tvzf ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} | \
	${SED} -n -e 's,^-.* ,${A_DATADIR}/,p' >> ${PLIST_SRC}

do-install:
	cd ${DESTDIR}${PREFIX}/${A_DATADIR}; \
	${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}
	cd ${DESTDIR}${PREFIX} ; \
	${FIND} . \( -name \*.png -or \
	          -name \*.gif -or \
	          -name \*.jpg -or \
	          -name \*.js  -or \
	          -name \*.swf -or \
	          -name \*.th  -or \
	          -name \*.css -or \
		  -name \*.txt -or \
		  -name \*hide_album -or \
		  -name data-changelog \
		\) \
	-exec ${CHMOD} 0644 '{}' \;

post-install:
# copy perl replaced scripts
	cd ${DESTDIR}${PREFIX}/${A_DATADIR}; \
	(cd ${WRKSRC}; ${TAR} -cf - ${EXTRACT_ELEMENTS} ) | \
	${TAR} -xf -

.include "../../mk/bsd.pkg.mk"
