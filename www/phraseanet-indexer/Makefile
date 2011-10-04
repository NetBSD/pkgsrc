# $NetBSD: Makefile,v 1.1.1.1 2011/10/04 08:02:19 manu Exp $
#

.include "../../www/phraseanet/Makefile.common"
PKGNAME=        phraseanet-indexer-${VERS}

PKG_DESTDIR_SUPPORT=	user-destdir
EXTRACT_ELEMENTS=	${DISTNAME}/bin/src/phraseanet_indexer
WRKSRC=			${WRKDIR}/${DISTNAME}/bin/src/phraseanet_indexer
USE_LANGUAGES=		c c++
USE_TOOLS+=		aclocal autoconf automake
GNU_CONFIGURE=		yes
CFLAGS+=	-I${BUILDLINK_PREFIX.libxml2}/include/libxml2


pre-configure:
	cd ${WRKSRC} && aclocal && automake -a && autoconf

.include "../../mk/mysql.buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
