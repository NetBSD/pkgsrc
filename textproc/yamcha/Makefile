# $NetBSD: Makefile,v 1.3.8.1 2012/10/05 13:22:23 tron Exp $
#

.include "Makefile.common"
PKGREVISION=	2

CATEGORIES=	devel

COMMENT=	Yet Another Multipurpose CHunk Annotator

PKG_DESTDIR_SUPPORT=	user-destdir

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
