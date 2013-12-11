# $NetBSD: Makefile,v 1.19 2013/12/11 16:13:22 fhajny Exp $
#

DISTNAME=	varnish-3.0.5
CATEGORIES=	www
MASTER_SITES=	http://repo.varnish-cache.org/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://varnish-cache.org/
COMMENT=	High-performace HTTP accelerator
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
BUILD_DEFS+=	VARBASE

EGDIR=			${PREFIX}/share/examples/varnish
CONF_FILES=		${EGDIR}/default.vcl ${PKG_SYSCONFDIR}/default.vcl

VRNUSER?=		varnish
VRNGROUP?=		${VRNUSER}
STATEDIR=		${VARBASE}/db
VRNDIR=			${STATEDIR}/${PKGBASE}

CONFIGURE_ARGS+=	--localstatedir=${STATEDIR}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
OWN_DIRS+=		${VRNDIR}
OWN_DIRS_PERMS+=	${VRNDIR} ${VRNUSER} ${VRNGROUP} 0770

PKG_GROUPS+=		${VRNGROUP}
PKG_USERS+=		${VRNUSER}:${VRNGROUP}
PKG_HOME.${VRNUSER}=	${VRNDIR}
PKG_SHELL.${VRNUSER}=	${SH}
PKG_GECOS.${VRNUSER}=	Varnish daemon user

RCD_SCRIPTS=		varnishd varnishlog varnishncsa
PYTHON_FOR_BUILD_ONLY=	yes

REPLACE_PYTHON+=	lib/libvcl/generate.py
REPLACE_PYTHON+=	lib/libvmod_std/vmod.py

.include "../../lang/python/pyversion.mk"
BUILD_DEPENDS+=		${PYPKGPREFIX}-docutils>=0.5:../../textproc/py-docutils

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
.  if ${PKGSRC_COMPILER} == "sunpro"
CONFIGURE_ENV+=	VCC_CC="cc ${_COMPILER_ABI_FLAG.${ABI}} -Kpic -G -o %o %s"
.  else
CONFIGURE_ENV+=	VCC_CC="gcc ${_COMPILER_ABI_FLAG.${ABI}} -fpic -shared -o %o %s"
.  endif
.endif

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
