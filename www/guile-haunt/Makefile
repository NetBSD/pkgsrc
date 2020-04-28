# $NetBSD: Makefile,v 1.2 2020/04/28 11:46:30 nikita Exp $

DISTNAME=	haunt-0.2.4
PKGNAME=	guile-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	https://files.dthompson.us/haunt/

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://files.dthompson.us/haunt/
COMMENT=	Functional static web site generator
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
GUILE_NEED_BOOTSTRAP=	yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/guile/2.2
USE_TOOLS+=		pkg-config
INFO_FILES=		yes

# \todo: add guile-reader, for Skribe support
DEPENDS+=	guile-commonmark-[0-9]*:../../textproc/guile-commonmark

# There is no check for guile scripts, the @GUILE@ ends up
# in the package with the WRKSRC/BL3 location of guile.
SUBST_CLASSES+=		guile
SUBST_STAGE.guile=	pre-configure
SUBST_FILES.guile=	scripts/haunt.in
SUBST_SED.guile+=	-e 's,@GUILE@,${PREFIX}/guile/2.2/bin/guile,g'

.include "../../lang/guile22/module.mk"
.include "../../mk/bsd.pkg.mk"
