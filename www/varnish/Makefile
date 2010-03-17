# $NetBSD: Makefile,v 1.7 2010/03/17 17:45:44 fhajny Exp $
#

DISTNAME=	varnish-2.0.6
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=varnish/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://varnish-cache.org/
COMMENT=	High-performace HTTP accelerator
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf
BUILD_DEFS+=	VARBASE

EGDIR=			${PREFIX}/share/examples/varnish
PKG_SYSCONFSUBDIR=	varnish
CONF_FILES=		${EGDIR}/default.vcl ${PKG_SYSCONFDIR}/default.vcl

VRNUSER?=		varnish
VRNGROUP?=		${VRNUSER}
STATEDIR=		${VARBASE}/db
VRNDIR=			${STATEDIR}/${PKGBASE}

CONFIGURE_ARGS+=	--localstatedir=${STATEDIR}
OWN_DIRS+=		${VRNDIR}
OWN_DIRS_PERMS+=	${VRNDIR} ${VRNUSER} ${VRNGROUP} 0770

PKG_GROUPS+=		${VRNGROUP}
PKG_USERS+=		${VRNUSER}:${VRNGROUP}
PKG_HOME.${VRNUSER}=	${VRNDIR}
PKG_SHELL.${VRNUSER}=	${SH}
PKG_GECOS.${VRNUSER}=	Varnish daemon user

SUBST_CLASSES+=		pkg
SUBST_STAGE.pkg=	post-patch
SUBST_MESSAGE.pkg=	Fixing pkgsrc paths
SUBST_FILES.pkg=	etc/Makefile.in
SUBST_SED.pkg=		-e 's,@EGDIR@,${EGDIR},'

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
.  if ${PKGSRC_COMPILER} == "sunpro"
CONFIGURE_ENV+=	VCC="cc -Kpic -G -o %o %s"
.  else
CONFIGURE_ENV+=	VCC_CC="gcc -fpic -shared -o %o %s"
.  endif
.endif

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
