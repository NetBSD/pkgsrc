# New ports collection makefile for:	tkinfo
# Version required:     1.5
# Date created:         16 Jan 1995
# Whom:                 thomas@ghpc8.ihf.rwth-aachen.de
#
# $NetBSD: Makefile,v 1.3 1998/01/25 00:19:55 hubertf Exp $
# FreeBSD Id: Makefile,v 1.15 1997/12/16 09:26:12 tg Exp
#

DISTNAME=	tkinfo-1.5
CATEGORIES=	misc tk80
MASTER_SITES=	http://www.math.ucsb.edu/~boldt/tkinfo/ \
		http://math-www.uni-paderborn.de/~axel/tkinfo/

MAINTAINER=	tg@freebsd.org

RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11/tk80

NO_BUILD=	yes

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/tkinfo ${PREFIX}/bin

post-patch:
	( cd ${WRKSRC} ; ${SED} 's|@PREFIX@|'${PREFIX}'|g' \
		<tkinfo >tkinfo.BAK ; ${MV} tkinfo.BAK tkinfo )

.include <bsd.port.mk>
