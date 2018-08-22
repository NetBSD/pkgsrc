# $NetBSD: Makefile,v 1.12 2018/08/22 09:47:14 wiz Exp $
#

.include "Makefile.common"
PKGREVISION=	8

CATEGORIES=	devel

COMMENT=	Yet Another Multipurpose CHunk Annotator

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++03
USE_TOOLS+=	perl:run gzip:run

CONFIGURE_ENV+=		ac_cv_path_GZIP=${TOOLS_PATH.gzip:Q}
CONFIGURE_ARGS+=	--with-perl5=${PERL5:Q}
CONFIGURE_ARGS+=	--with-svm-learn=${BUILDLINK_PREFIX.TinySVM}/bin/svm_learn

TEST_TARGET=	check

.include "../../math/TinySVM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
