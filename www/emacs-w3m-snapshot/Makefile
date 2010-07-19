# $NetBSD: Makefile,v 1.4 2010/07/19 21:17:34 perry Exp $

DISTNAME=	w3m-el-snapshot_1.4.394+0.20100524.orig
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME:S/w3m-el-snapshot_/emacs-w3m-/:S/+0//:S/.orig//}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/w/w3m-el-snapshot/}

MAINTAINER=	makoto@ki.nu
HOMEPAGE=	http://emacs-w3m.namazu.org/
COMMENT=	Emacs frontend for w3m browser

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	makeinfo gzip autoconf
INFO_FILES=	yes

DEPENDS+=	w3m>=0.5.2nb3:../../www/w3m

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--srcdir=${WRKSRC}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ENV+=		GAMEOWN=${GAMEOWN}
BUILD_TARGET=
WRKSRC=			${WRKDIR}/emacs-w3m

INSTALL_MAKE_FLAGS=	prefix=${DESTDIR}${PREFIX} \
			infodir=${DESTDIR}${PREFIX}/${PKGINFODIR}

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		GAMEDATAMODE

PLIST_SRC+=		PLIST

.include "options.mk"

.include "../../devel/apel/buildlink3.mk"
.include "../../devel/flim/buildlink3.mk"
.include "../../editors/mule-ucs/buildlink3.mk"

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../mk/bsd.pkg.mk"
