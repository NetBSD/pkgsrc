# $NetBSD: Makefile,v 1.16 2007/12/23 04:50:30 minskim Exp $
#

DISTNAME=		wdiff-0.5
PKGREVISION=		2
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GNU:=wdiff/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/wdiff/wdiff.html
COMMENT=		Word-by-word diff

GNU_CONFIGURE=		yes
CONFIGURE_HAS_INFODIR=	no
CONFIGURE_HAS_MANDIR=	no

USE_TOOLS+=		makeinfo
INFO_FILES=		# PLIST
INSTALLATION_DIRS=	bin ${PKGINFODIR} ${PKGMANDIR}/man1 share/doc/wdiff

# pkgsrc does not provide libtermcap, but ncurses does provide
# libtermcap routines.
.if !exists(/usr/lib/libtermcap.so)
BUILDLINK_TRANSFORM+=	l:termcap:ncurses
.  include "../../devel/ncurses/buildlink3.mk"
.endif

do-install:
	${INSTALL_MAN} ${WRKSRC}/wdiff.1 ${PREFIX}/${PKGMANDIR}/man1
	cd ${WRKSRC}; for f in wdiff.info wdiff.info-[0-9]*; do		\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_MAN} "$$f" ${PREFIX}/${PKGINFODIR};		\
	done
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wdiff
	${INSTALL_PROGRAM} ${WRKSRC}/wdiff ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
