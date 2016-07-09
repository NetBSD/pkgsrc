# $NetBSD: Makefile,v 1.10 2016/07/09 06:39:08 wiz Exp $
#

.include "Makefile.common"
PKGREVISION=	7

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
