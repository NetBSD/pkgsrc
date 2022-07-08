# $NetBSD: Makefile,v 1.37 2022/07/08 22:07:33 wiz Exp $

DISTNAME=	varnish-7.1.0
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://varnish-cache.org/_downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://varnish-cache.org/
COMMENT=	High-performace HTTP accelerator
LICENSE=	modified-bsd

BUILD_DEPENDS+=			${PYPKGPREFIX}-docutils>=0.12:../../textproc/py-docutils
TOOL_DEPENDS+=			${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

PYTHON_VERSIONS_INCOMPATIBLE=	27

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

BUILD_DEFS+=	VARBASE
BUILD_DEFS+=	PKG_SYSCONFBASE

PKG_SYSCONFSUBDIR=	varnish
EGDIR=			${PREFIX}/share/examples/varnish
CONF_FILES=		${EGDIR}/builtin.vcl \
			${PKG_SYSCONFDIR}/builtin.vcl

.include "../../mk/bsd.prefs.mk"

VRNUSER?=		varnish
VRNGROUP?=		${VRNUSER}
STATEDIR=		${VARBASE}/db
VRNDIR=			${STATEDIR}/${PKGBASE}

OWN_DIRS+=		${VRNDIR}
OWN_DIRS_PERMS+=	${VRNDIR} ${VRNUSER} ${VRNGROUP} 0770

PKG_GROUPS+=		${VRNGROUP}
PKG_USERS+=		${VRNUSER}:${VRNGROUP}
PKG_HOME.${VRNUSER}=	${VRNDIR}
PKG_SHELL.${VRNUSER}=	${SH}
PKG_GECOS.${VRNUSER}=	Varnish daemon user

FILES_SUBST+=		VRNUSER=${VRNUSER}
FILES_SUBST+=		VRNGROUP=${VRNGROUP}

REPLACE_PYTHON+=	lib/libvcc/vmodtool.py
REPLACE_PYTHON+=	lib/libvsc/vsctool.py

CONFIGURE_ARGS+=	--localstatedir=${STATEDIR}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ARGS+=	--with-rst2html=${PREFIX}/bin/rst2html-${PYVERSSUFFIX}
CONFIGURE_ARGS+=	--with-rst2man=${PREFIX}/bin/rst2man-${PYVERSSUFFIX}
CONFIGURE_ARGS+=	--with-sphinx-build=${PREFIX}/bin/sphinx-build-${PYVERSSUFFIX}

# Explicitly disable epoll on illumos, provided for Linux compat only.
CONFIGURE_ARGS.SunOS+=	--disable-epoll

.include "../../mk/compiler.mk"

# Fixes build on at least SunOS/i386
# See https://github.com/varnishcache/varnish-cache/issues/1875
.if !empty(CC_VERSION:Mgcc*) && ${MACHINE_ARCH} == "i386"
CFLAGS+=		-fexcess-precision=standard
.endif
LDFLAGS.NetBSD+=	-lm	# for ldexp

INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

# not signed/unsigned char safe
BUILDLINK_TRANSFORM+=	rm:-Werror

PKGCONFIG_OVERRIDE+=	varnishapi.pc.in

RCD_SCRIPTS=		varnishd varnishlog varnishncsa

TEST_TARGET=		check

.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
