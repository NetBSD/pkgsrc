# New ports collection makefile for:	rman
# Version required:     3.0.4
# Date created:         27 Dec 1994
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $Id: Makefile,v 1.4 1998/01/22 10:26:40 agc Exp $
#

DISTNAME=       rman-3.0.4
CATEGORIES=	textproc
MASTER_SITES=   ftp://ftp.cs.berkeley.edu/ucb/people/phelps/tcltk/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tg@FreeBSD.org

NO_CDROM=	"License required"
MIRROR_DISTFILE=	no
MAN1=		rman.1

post-install:
	@strip ${PREFIX}/bin/rman

.include <bsd.port.mk>
