# $NetBSD: Makefile,v 1.3 2000/04/07 03:51:54 itojun Exp $

DISTNAME=	intlfonts-1.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNU:=intlfonts/intlfonts-1.2-split/}
DISTFILES=	${FONT_SETS:S/$/${EXTRACT_SUFX}/} ${MISC_FILES}

MAINTAINER=	packages@netbsd.org

FONT_SETS=	Asian		\
		Chinese		\
		Ethiopic	\
		European	\
		Japanese	\
		Misc

# These are extra files that not many folks will likely need or want
# They are all bigger than 24 dots -- you'll only want them if you
# want to display text in really big fonts.
#
EXTRA_FONTS=	Chinese.BIG	\
		European.BIG	\
		Japanese.BIG

# Type1/TrueType fonts for Latin1, Thai and Vietnamese
# XXX need "fonts.scale" for them
#
#EXTRA_FONTS+=	Type1		\
#		TrueType
#CONFIGURE_ARGS+=--with-type1 --with-truetype

MISC_FILES=	README.split

DIST_SUBDIR=	intlfonts
EXTRACT_ONLY=	${FONT_SETS:S/$/${EXTRACT_SUFX}/}
MESSAGE_FILE=	${WRKSRC}/MESSAGE
USE_X11BASE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-fontdir=${PREFIX}/lib/X11/fonts/intlfonts \
		--without-bdf --enable-compress=gzip

post-extract:
.for FILE in ${MISC_FILES}
	${CP} ${_DISTDIR}/${FILE} ${WRKSRC}
.endfor

do-build:
	${SED} -e 's#@PREFIX@#${PREFIX}#g' <${PKGDIR}/MESSAGE >${MESSAGE_FILE}

.include "../../mk/bsd.pkg.mk"
