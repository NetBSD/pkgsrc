# New ports collection makefile for:	tkman
# Version required:     1.8
# Date created:         27 Dec 1994
# Whom:                 thomas Gellekum <tg@freebsd.org>
#
# $NetBSD: Makefile,v 1.8 1998/03/10 16:44:47 frueauf Exp $
# FreeBSD Id: Makefile,v 1.28 1997/12/08 15:51:20 tg Exp
#

DISTNAME=		tkman-2.0.4
CATEGORIES=		misc tk80
MASTER_SITES=		ftp://ftp.cs.berkeley.edu/ucb/people/phelps/tcltk/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		tg@freebsd.org

LIB_DEPENDS=		tk80.1.:${PORTSDIR}/x11/tk80
RUN_DEPENDS=		rman:${PORTSDIR}/textproc/rman \
			glimpse:${PORTSDIR}/textproc/glimpse

NO_CDROM=		"Don't sell for profit"
MIRROR_DISTFILE=	no

.include <bsd.port.mk>
