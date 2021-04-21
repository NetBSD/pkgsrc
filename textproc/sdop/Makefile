# $NetBSD: Makefile,v 1.2 2021/04/21 08:11:17 wiz Exp $

DISTNAME=	sdop-0.80
CATEGORIES=	textproc
MASTER_SITES=	# ftp://ftp.csx.cam.ac.uk/pub/software/wordprocessing/unix/sdop/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://github.com/Exim/exim/wiki/XpftDocs
COMMENT=	Simple DocBook processor
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

MAKE_ENV+=	SHELL=${SH}

BUILD_TARGET=	build

.include "../../mk/bsd.pkg.mk"
