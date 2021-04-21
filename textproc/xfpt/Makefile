# $NetBSD: Makefile,v 1.2 2021/04/21 08:11:17 wiz Exp $

DISTNAME=	xfpt-0.09
CATEGORIES=	textproc
MASTER_SITES=	# ftp://ftp.csx.cam.ac.uk/pub/software/wordprocessing/unix/xfpt/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://github.com/Exim/exim/wiki/XpftDocs
COMMENT=	Converts simple plain text markup into DocBook XML
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

MAKE_ENV+=	SHELL=${SH}

BUILD_TARGET=	build

.include "../../mk/bsd.pkg.mk"
