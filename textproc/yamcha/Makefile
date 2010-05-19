# $NetBSD: Makefile,v 1.1.1.1 2010/05/19 12:08:02 obache Exp $
#

.include "Makefile.common"

CATEGORIES=	devel

COMMENT=	Yet Another Multipurpose CHunk Annotator

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	perl:run

CONFIGURE_ARGS+=	--with-perl5=${PERL5:Q}
CONFIGURE_ARGS+=	--with-svm-learn=${BUILDLINK_PREFIX.TinySVM}/bin/svm_learn

TEST_TARGET=	check

.include "../../math/TinySVM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
