# New ports collection makefile for:   kde
# Version required:    Beta3
# Date created:        4 November 1997
# Whom:                Satoshi Asami <asami@freebsd.org>
#
# $NetBSD: Makefile,v 1.5 1998/04/14 11:41:54 hubertf Exp $
# FreeBSD Id: Makefile,v 1.2 1997/11/27 00:47:46 se Exp
#

DISTNAME=	kde-3.1b
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	se@freebsd.org

LIB_DEPENDS=	kdecore.0.90:${PORTSDIR}/x11/kdelibs
RUN_DEPENDS=	kwm:${PORTSDIR}/x11/kdebase \
		kcalc:${PORTSDIR}/misc/kdeutils \
		kmahjongg:${PORTSDIR}/games/kdegames \
		kmail:${PORTSDIR}/net/kdenetwork

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
