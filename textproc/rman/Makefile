# New ports collection makefile for:	rman
# Version required:     3.0.4
# Date created:         27 Dec 1994
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $NetBSD: Makefile,v 1.5 1998/01/24 23:44:25 hubertf Exp $
# FreeBSD Id: Makefile,v 1.17 1997/12/08 15:45:27 tg Exp
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
