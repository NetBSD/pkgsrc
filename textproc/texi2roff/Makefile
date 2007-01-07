# $NetBSD: Makefile,v 1.9 2007/01/07 09:14:14 rillig Exp $

DISTNAME=		texi2roff-2.0
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_TEX_CTAN:=support/texi2roff/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://texinfo.org/texi2roff/
COMMENT=		Texinfo-to-ROFF direct translator

BUILD_TARGET=
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/texi2roff ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/texi2roff.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
