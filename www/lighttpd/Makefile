# $NetBSD: Makefile,v 1.88 2020/04/12 08:29:17 adam Exp $

DISTNAME=	lighttpd-1.4.55
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://download.lighttpd.net/lighttpd/releases-1.4.x/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.lighttpd.net/
COMMENT=	Fast, light-footprint HTTP server
LICENSE=	modified-bsd

USE_LIBTOOL=			yes
SHLIBTOOL_OVERRIDE=		# empty
USE_TOOLS+=			pkg-config
GNU_CONFIGURE=			yes
GNU_CONFIGURE_LIBSUBDIR=	${PKGBASE}
CONFIGURE_ARGS+=		--with-pcre
TEST_TARGET=			check

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
PKG_SYSCONFSUBDIR=	${PKGBASE}
RCD_SCRIPTS=		lighttpd

.include "options.mk"

CNFS_cmd=		${SED} -ne "s,^share/examples/lighttpd/,,p" PLIST
CNFS=			${CNFS_cmd:sh}
.for file in ${CNFS}
CONF_FILES+=		${EGDIR}/${file:Q} ${PKG_SYSCONFDIR}/${file:Q}
.endfor

BUILD_DEFS+=		VARBASE LIGHTTPD_LOGDIR LIGHTTPD_STATEDIR
BUILD_DEFS+=		LIGHTTPD_CACHEDIR LIGHTTPD_HOMEDIR
BUILD_DEFS+=		LIGHTTPD_USER LIGHTTPD_GROUP

.include "../../mk/bsd.prefs.mk"

LIGHTTPD_CACHEDIR?=	${VARBASE}/cache/lighttpd
LIGHTTPD_HOMEDIR?=	${VARBASE}/lib/lighttpd
LIGHTTPD_LOGDIR?=	${VARBASE}/log/lighttpd
LIGHTTPD_STATEDIR?=	${VARBASE}/run
LIGHTTPD_USER?=		lighttpd
LIGHTTPD_GROUP?=	lighttpd
PKG_GROUPS+=		${LIGHTTPD_GROUP}
PKG_USERS+=		${LIGHTTPD_USER}:${LIGHTTPD_GROUP}
PKG_GROUPS_VARS+=	LIGHTTPD_GROUP
PKG_USERS_VARS+=	LIGHTTPD_USER

INSTALLATION_DIRS+=	${DOCDIR} ${EGDIR} ${EGDIR}/conf.d ${EGDIR}/vhosts.d
OWN_DIRS=		${PKG_SYSCONFDIR}/conf.d
OWN_DIRS+=		${PKG_SYSCONFDIR}/vhosts.d
OWN_DIRS_PERMS=		${LIGHTTPD_LOGDIR} ${LIGHTTPD_USER} ${LIGHTTPD_GROUP} 0755
OWN_DIRS+=		${LIGHTTPD_STATEDIR}

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing config file paths
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	doc/config/lighttpd.conf doc/lighttpd.8
SUBST_VARS.path=	LIGHTTPD_LOGDIR LIGHTTPD_STATEDIR LIGHTTPD_USER \
			LIGHTTPD_CACHEDIR LIGHTTPD_HOMEDIR              \
			LIGHTTPD_GROUP PKG_SYSCONFDIR VARBASE

post-install:
	set -e; cd ${WRKSRC}/doc;				\
	for f in *.css outdated/*.dot outdated/*.txt; do	\
		${INSTALL_DATA} $$f ${DESTDIR}${DOCDIR};	\
	done;							\
	for f in config/*.conf scripts/*.sh; do			\
		${INSTALL_DATA} $$f ${DESTDIR}${EGDIR};		\
	done;							\
	for f in config/conf.d/*.conf config/conf.d/mod.*; do	\
		${INSTALL_DATA} $$f ${DESTDIR}${EGDIR}/conf.d;	\
	done;							\
	${INSTALL_DATA} config/vhosts.d/*.template ${DESTDIR}${EGDIR}/vhosts.d

.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
