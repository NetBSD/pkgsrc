# $NetBSD: Makefile,v 1.71 2022/06/28 11:37:48 wiz Exp $

DISTNAME=	${PKGNAME_NOREV}-stable-src
PKGNAME=	privoxy-3.0.29
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	https://www.privoxy.org/sf-download-mirror/Sources/${PKGVERSION_NOREV}%20(stable)/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.privoxy.org/
COMMENT=	Web proxy with advanced filtering capabilities
LICENSE=	gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"

PRIVOXY_USER?=		privoxy
PRIVOXY_GROUP?=		privoxy
PKG_GROUPS_VARS+=	PRIVOXY_GROUP
PKG_USERS_VARS+=	PRIVOXY_USER

PKG_SYSCONFSUBDIR?=	privoxy

RCD_SCRIPTS=		privoxy
PKG_GROUPS=		${PRIVOXY_GROUP}
PKG_USERS=		${PRIVOXY_USER}:${PRIVOXY_GROUP}

EGDIR=			${PREFIX}/share/examples/privoxy

CPPFLAGS+=		-Dunix

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}-stable

USE_FEATURES=		snprintf
USE_TOOLS+=		gmake mktemp autoconf autoheader
BUILD_DEFS+=		VARBASE
MAKE_FILE=		GNUmakefile

USE_TOOLS+=		perl

PTHREAD_AUTO_VARS=	yes
PTHREAD_OPTS+=		require

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${EGDIR:Q}
CONFIGURE_ARGS+=	--with-user=${PRIVOXY_USER:Q}
CONFIGURE_ARGS+=	--with-group=${PRIVOXY_GROUP:Q}
CONFIGURE_ARGS+=	--enable-compression

USER_GROUP=		${PRIVOXY_USER} ${PRIVOXY_GROUP}

.for i in \
    config trust default.action user.action user.filter default.filter match-all.action
CONF_FILES_PERMS+=	${EGDIR}/${i} ${PKG_SYSCONFDIR}/${i} ${USER_GROUP} 0660
.endfor

OWN_DIRS_PERMS+=	/var/log/privoxy ${USER_GROUP} 0775
CONF_FILES_PERMS+=	/dev/null /var/log/privoxy/logfile ${USER_GROUP} 0660

FILES_SUBST+=		PRIVOXY_USER=${PRIVOXY_USER:Q}

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	config
SUBST_VARS.paths=	PKG_SYSCONFDIR
SUBST_STAGE.paths=	pre-configure

.include "options.mk"

pre-configure:
	cd ${WRKSRC} && autoheader && autoconf

.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
