# $NetBSD: Makefile,v 1.7 1998/08/20 15:17:38 tsarna Exp $
# FreeBSD Id: Makefile,v 1.15 1997/12/16 09:26:12 tg Exp
#

DISTNAME=	tkinfo-1.5
CATEGORIES=	misc tk80
MASTER_SITES=	http://www.math.ucsb.edu/~boldt/tkinfo/ \
		http://math-www.uni-paderborn.de/~axel/tkinfo/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://math-www.uni-paderborn.de/~axel/tkinfo/

RUN_DEPENDS=	wish8.0:../../x11/tk80

NO_BUILD=	yes

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/tkinfo ${PREFIX}/bin

post-patch:
	( cd ${WRKSRC} ; ${SED} 's|@PREFIX@|'${PREFIX}'|g' \
		<tkinfo >tkinfo.BAK ; ${MV} tkinfo.BAK tkinfo )

.include "../../mk/bsd.pkg.mk"
