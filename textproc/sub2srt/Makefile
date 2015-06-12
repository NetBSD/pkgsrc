# $NetBSD: Makefile,v 1.7 2015/06/12 10:51:41 wiz Exp $

DISTNAME=	sub2srt-0.5.3
PKGREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://www.robelix.com/sub2srt/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.robelix.com/sub2srt/
COMMENT=	Simple tool to convert 2 common subtitle formats to subviewer format

USE_TOOLS+=		perl:run
USE_LANGUAGES=		# empty

REPLACE_PERL+=		sub2srt
INSTALLATION_DIRS=	bin

do-build:		# nothing

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sub2srt ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
