# New ports collection makefile for:	tkman
# Version required:     1.8
# Date created:         27 Dec 1994
# Whom:                 thomas Gellekum <tg@freebsd.org>
#
# $Id: Makefile,v 1.5 1998/01/22 10:26:41 agc Exp $
#

DISTNAME=	tkman-2.0.4
CATEGORIES=	misc tk80
MASTER_SITES=	ftp://ftp.cs.berkeley.edu/ucb/people/phelps/tcltk/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tg@freebsd.org

LIB_DEPENDS=	tk80\\.1\\.:${PORTSDIR}/x11/tk80
RUN_DEPENDS=	rman:${PORTSDIR}/textproc/rman \
		glimpse:${PORTSDIR}/textproc/glimpse

NO_CDROM=	"Don't sell for profit"
MIRROR_DISTFILE=	no
MAN1=		tkman.1

.include <bsd.port.mk>
