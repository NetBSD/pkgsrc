# $NetBSD: Makefile,v 1.8 2018/08/16 18:55:13 adam Exp $

DISTNAME=	translate-shell-0.9.6.8
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=soimort/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://www.soimort.org/translate-shell/
COMMENT=	Command-line translator
LICENSE=	unlicense

USE_LANGUAGES=	# none
USE_TOOLS+=	bash:run gawk:run

DEPENDS+=	rlwrap-[0-9]*:../../misc/rlwrap

SUBST_CLASSES+=		shebang
SUBST_FILES.shebang=	build/trans
SUBST_SED.shebang=	-e 's,/usr/bin/env bash,${BASH},'
SUBST_STAGE.shebang=	post-build

BUILD_TARGET=		build

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/build/trans ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/trans.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../audio/mpg123/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
