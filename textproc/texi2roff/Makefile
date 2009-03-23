# $NetBSD: Makefile,v 1.10 2009/03/23 00:32:10 joerg Exp $

DISTNAME=		texi2roff-2.0
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_TEX_CTAN:=support/texi2roff/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://texinfo.org/texi2roff/
COMMENT=		Texinfo-to-ROFF direct translator

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/texi2roff ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/texi2roff.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
