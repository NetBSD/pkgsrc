# $NetBSD: Makefile,v 1.7 2013/05/31 12:42:24 wiz Exp $
#

.include "Makefile.common"
PKGREVISION=	4

CATEGORIES=	devel

COMMENT=	Yet Another Multipurpose CHunk Annotator

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	perl:run gzip:run

CONFIGURE_ENV+=		ac_cv_path_GZIP=${TOOLS_PATH.gzip:Q}
CONFIGURE_ARGS+=	--with-perl5=${PERL5:Q}
CONFIGURE_ARGS+=	--with-svm-learn=${BUILDLINK_PREFIX.TinySVM}/bin/svm_learn

TEST_TARGET=	check

.include "../../math/TinySVM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
