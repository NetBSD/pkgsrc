# $NetBSD: Makefile,v 1.11 1999/04/26 19:30:28 garbled Exp $
# FreeBSD Id: Makefile,v 1.15 1997/12/16 09:26:12 tg Exp
#

DISTNAME=	tkinfo-1.5
CATEGORIES=	x11 tk80
MASTER_SITES=	http://www.math.ucsb.edu/~boldt/tkinfo/ \
		http://math-www.uni-paderborn.de/~axel/tkinfo/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://math-www.uni-paderborn.de/~axel/tkinfo/

DEPENDS=	tk-8.0.5:../../x11/tk80

USE_X11=	yes
NO_BUILD=	yes

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/tkinfo ${PREFIX}/bin

post-patch:
	( cd ${WRKSRC} ; ${SED} 's|@PREFIX@|${PREFIX}|g' \
		<tkinfo >tkinfo.BAK ; ${MV} tkinfo.BAK tkinfo )

.include "../../mk/bsd.pkg.mk"
