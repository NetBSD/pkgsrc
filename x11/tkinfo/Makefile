# $NetBSD: Makefile,v 1.4 1998/04/15 10:38:55 agc Exp $
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

.include "../../mk/bsd.pkg.mk"
