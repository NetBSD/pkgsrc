# $NetBSD: Makefile,v 1.6 2014/05/29 23:37:49 wiz Exp $

DISTNAME=	sub2srt-0.5.3
PKGREVISION=	3
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
