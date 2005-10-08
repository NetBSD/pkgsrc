# $NetBSD: Makefile,v 1.11 2005/10/08 19:06:25 reed Exp $
#

DISTNAME=		wdiff-0.5
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GNU:=wdiff/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/wdiff/wdiff.html
COMMENT=		Word-by-word diff

GNU_CONFIGURE=		yes
CONFIGURE_HAS_INFODIR=	no
CONFIGURE_HAS_MANDIR=	no

USE_MAKEINFO=		yes
INFO_FILES=		wdiff.info
INSTALLATION_DIRS=	bin ${INFO_DIR} ${PKGMANDIR}/man1 share/doc/wdiff
CPPFLAGS+=		-DHAVE_STRERROR

# pkgsrc does not provide libtermcap, but ncurses does provide
# libtermcap routines.
.if !exists(/usr/lib/libtermcap.so)
BUILDLINK_TRANSFORM+=	l:termcap:ncurses
.  include "../../devel/ncurses/buildlink3.mk"
.endif

do-install:
	${INSTALL_MAN} ${WRKSRC}/wdiff.1 ${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/wdiff.info ${PREFIX}/${INFO_DIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wdiff/
	${INSTALL_PROGRAM} ${WRKSRC}/wdiff ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
