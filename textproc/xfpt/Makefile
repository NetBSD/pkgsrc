# $NetBSD: Makefile,v 1.1 2018/06/15 13:08:52 prlw1 Exp $

DISTNAME=	xfpt-0.09
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/wordprocessing/unix/xfpt/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://github.com/Exim/exim/wiki/XpftDocs
COMMENT=	Converts simple plain text markup into DocBook XML
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

MAKE_ENV+=	SHELL=${SH}

BUILD_TARGET=	build

.include "../../mk/bsd.pkg.mk"
