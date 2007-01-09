# $NetBSD: Makefile,v 1.14 2007/01/09 05:40:21 rillig Exp $

DISTNAME=		sawfish-themes-0.2
PKGREVISION=		6
CATEGORIES=		x11 wm
DISTFILES=		${SAWFISH_THEMES}

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		http://themes.freshmeat.net/browse/926/
COMMENT=		Themes for the sawfish window manager

DEPENDS+=		sawfish>=1.0.1:../../wm/sawfish

EXTRACT_DIR=		${WRKSRC}
DIST_SUBDIR=		sawfish-themes
THEMES_DIR=		share/sawfish/themes
PLIST_SRC=		${WRKDIR}/PLIST

NO_BUILD=		yes
NO_CONFIGURE=		yes

CHECK_INTERPRETER_SKIP+=	*.pl

.include "../../mk/bsd.prefs.mk"

.include "../../mk/x11.buildlink3.mk"

pre-fetch:
	@${ECHO} "==========================================================="
	@${ECHO}
	@${ECHO} " We're now downloading >150 themes for Sawfish - if you"
	@${ECHO} " would like to install only a subset, you can specify the"
	@${ECHO} " themes using the SAWFISH_THEMES environment variable."
	@${ECHO} " (See ${FILESDIR}/themes.sawfish for defaults.)"
	@${ECHO}
	@${ECHO} "==========================================================="
	@sleep 5

post-extract:
	chmod -R u+rw,go-w ${WRKSRC}
	find ${WRKSRC} -type f | xargs chmod -x
	find ${WRKSRC} -type d \( -name ".xvpics" -or -name "CVS" \) -print \
	| xargs rm -fr

# here's what we do:
# - create a PLIST
# - dirrm directives need to be reversed in case of subdirs
pre-install:
	set -e; cd ${WRKSRC};						\
	exec 1> ${PLIST_SRC};						\
	find * \( -type f -or -type l \) -print				\
	| sed -e 's,^,share/sawfish/themes/,';				\
	find -d * \( -type d ! -name "." \) -print			\
	| sed -e 's,^,@dirrm share/sawfish/themes/,';			\
	${ECHO} "@dirrm share/sawfish/themes"

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${THEMES_DIR}
	cd ${WRKSRC} && pax -s',^PLIST$$,,' -rw * ${PREFIX}/${THEMES_DIR}

.include "files/themes.sawfish"
.include "../../mk/bsd.pkg.mk"
