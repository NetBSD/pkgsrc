# $NetBSD: Makefile,v 1.14 2022/06/28 11:36:49 wiz Exp $

DISTNAME=	sub2srt-0.5.5
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=robelix/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/robelix/sub2srt
COMMENT=	Simple tool to convert 2 common subtitle formats to subviewer format

USE_TOOLS+=		perl:run
USE_LANGUAGES=		# empty

REPLACE_PERL+=		sub2srt
INSTALLATION_DIRS=	bin

do-build:		# nothing

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sub2srt ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
