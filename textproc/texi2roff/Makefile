# $NetBSD: Makefile,v 1.8 2006/12/15 14:34:21 wiz Exp $

DISTNAME=		texi2roff-2.0
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_TEX_CTAN:=support/texi2roff/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://texinfo.org/texi2roff/
COMMENT=		Texinfo-to-ROFF direct translator

BUILD_TARGET=
INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/texi2roff ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/texi2roff.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
