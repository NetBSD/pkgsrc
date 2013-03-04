# $NetBSD: Makefile,v 1.10 2013/03/04 19:12:22 hiramatsu Exp $

DISTNAME=	w3m-el-snapshot_1.4.483+0.20120614.orig
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME:S/w3m-el-snapshot_/emacs-w3m-/:S/+0//:S/.orig//}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/w/w3m-el-snapshot/}

MAINTAINER=	makoto@ki.nu
HOMEPAGE=	http://emacs-w3m.namazu.org/
COMMENT=	Emacs frontend for w3m browser
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	makeinfo gzip autoconf
INFO_FILES=	yes

DEPENDS+=	w3m{,-img}>=0.5.2nb3:../../www/w3m

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--srcdir=${WRKSRC}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ENV+=		GAMEOWN=${GAMES_USER}
BUILD_TARGET=
WRKSRC=			${WRKDIR}/w3m-el-snapshot-1.4.483+0.20120614.orig

EVAL_PREFIX+=	W3M_PREFIX=w3m

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	w3m.el
SUBST_SED.paths=	-e 's|@W3M@|${W3M_PREFIX}/bin/w3m|g'

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		GAMEDATAMODE

.include "options.mk"

.include "../../devel/apel/buildlink3.mk"
.include "../../devel/flim/buildlink3.mk"
.include "../../editors/mule-ucs/buildlink3.mk"

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../mk/bsd.pkg.mk"
