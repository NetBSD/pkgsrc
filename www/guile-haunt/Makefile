# $NetBSD: Makefile,v 1.8 2023/05/16 15:29:38 nikita Exp $

DISTNAME=	haunt-0.2.6
PKGNAME=	guile-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	https://files.dthompson.us/haunt/

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://files.dthompson.us/haunt/
COMMENT=	Functional static web site generator
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
GUILE_NEED_BOOTSTRAP=	yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/guile/3.0
USE_TOOLS+=		pkg-config
INFO_FILES=		yes

# TODO: add guile-reader, for Skribe support
DEPENDS+=	guile-commonmark-[0-9]*:../../textproc/guile-commonmark

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	inotify

.if ${OPSYS} == "Linux"
PLIST.inotify=	yes
.endif

# There is no check for guile scripts, the @GUILE@ ends up
# in the package with the WRKSRC/BL3 location of guile.
SUBST_CLASSES+=		guile
SUBST_STAGE.guile=	pre-configure
SUBST_FILES.guile=	scripts/haunt.in
SUBST_SED.guile+=	-e 's,@GUILE@,${PREFIX}/guile/3.0/bin/guile,g'

.include "../../lang/guile30/module.mk"
.include "../../mk/bsd.pkg.mk"
