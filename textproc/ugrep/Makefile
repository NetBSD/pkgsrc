# $NetBSD: Makefile,v 1.4 2020/08/31 18:12:19 wiz Exp $

DISTNAME=	ugrep-2.5.3
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Genivia/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Genivia/ugrep
COMMENT=	Fast grep with many enhancements including Unicode support
LICENSE=	modified-bsd

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	--with-bzlib
CONFIGURE_ARGS+=	--with-lz4
CONFIGURE_ARGS+=	--with-lzma	# lzma & xz files
CONFIGURE_ARGS+=	--with-zlib

UGREP_PDIR=		share/ugrep/patterns
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${UGREP_PDIR}

.for i in c++ c cpp cs html java js json markdown perl php python \
	ruby rust scala swift xml
INSTALLATION_DIRS+=	${UGREP_PDIR}/${i}
.endfor

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
