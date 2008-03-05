# $NetBSD: Makefile,v 1.17 2008/03/05 15:56:19 jlam Exp $
#

DISTNAME=		wdiff-0.5
PKGREVISION=		3
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GNU:=wdiff/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/wdiff/wdiff.html
COMMENT=		Word-by-word diff

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_HAS_INFODIR=	no
CONFIGURE_HAS_MANDIR=	no

USE_TOOLS+=		makeinfo
INFO_FILES=		# PLIST
INSTALLATION_DIRS=	bin ${PKGINFODIR} ${PKGMANDIR}/man1 share/doc/wdiff

do-install:
	${INSTALL_MAN} ${WRKSRC}/wdiff.1				\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	cd ${WRKSRC}; for f in wdiff.info wdiff.info-[0-9]*; do		\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_MAN} "$$f" ${DESTDIR}${PREFIX}/${PKGINFODIR};	\
	done
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/wdiff
	${INSTALL_PROGRAM} ${WRKSRC}/wdiff ${DESTDIR}${PREFIX}/bin

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
