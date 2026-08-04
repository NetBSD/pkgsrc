# $NetBSD: Makefile,v 1.2 2026/08/04 20:29:19 wiz Exp $

DISTNAME=	stumpwm-24.11
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=stumpwm/}
GITHUB_TAG=	${PKGVERSION_NOREV}
DIST_SUBDIR=	stumpwm

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://stumpwm.github.io/
COMMENT=	Tiling, keyboard driven window manager written in Common Lisp
LICENSE=	gnu-gpl-v2

PPCRE_VERSION=		2.1.2
CLX_VERSION=		0.7.6
ALEXANDRIA_VERSION=	1.4

DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	cl-ppcre-${PPCRE_VERSION}.tar.gz
DISTFILES+=	cl-clx-${CLX_VERSION}.tar.gz
DISTFILES+=	alexandria-${ALEXANDRIA_VERSION}.tar.gz

SITES.cl-ppcre-${PPCRE_VERSION}.tar.gz= \
	-https://github.com/edicl/cl-ppcre/archive/refs/tags/v${PPCRE_VERSION}.tar.gz
SITES.cl-clx-${CLX_VERSION}.tar.gz= \
	-https://github.com/sharplispers/clx/archive/refs/tags/${CLX_VERSION}.tar.gz
SITES.alexandria-${ALEXANDRIA_VERSION}.tar.gz= \
	-https://gitlab.common-lisp.net/alexandria/alexandria/-/archive/v${ALEXANDRIA_VERSION}/alexandria-v${ALEXANDRIA_VERSION}.tar.gz

USE_TOOLS=	autoconf gmake makeinfo
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-compression
INFO_FILES=	yes

DEPENDS+=	sbcl-[0-9]*:../../lang/sbcl

MAKE_ENV=	CL_SOURCE_REGISTRY=${WRKSRC}
MAKE_ENV+=	ASDF_OUTPUT_TRANSLATIONS=/:

MAKE_JOBS_SAFE=		NO
MKPIE_SUPPORTED=	no

SUBST_CLASSES+=		destdir
SUBST_SED.destdir+=	-e "s,destdir,DESTDIR,g"
SUBST_FILES.destdir+=	Makefile
SUBST_STAGE.destdir=	pre-build
SUBST_MESSAGE.destdir=	Use the real destdir

# Use symlinks so ASDF finds system dependencies
pre-configure:
	find ${WRKDIR} -type f -name \*.asd -a \! -name stumpwm.asd \
		-exec ln -s {} ${WRKSRC} \;
	cd ${WRKSRC} && ./autogen.sh

# Warning shouldn't fail the build
# https://bugs.launchpad.net/sbcl/+bug/2090967
pre-build:
	${ECHO} '(declaim (sb-ext:muffle-conditions cl:warning))' \
		> ${WRKDIR}/.home/.sbclrc

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../archivers/zstd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
