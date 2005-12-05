# $NetBSD: Makefile,v 1.20 2005/12/05 20:51:14 rillig Exp $
#

DISTNAME=	${PKGNAME_NOREV}-stable-src
PKGNAME=	privoxy-3.0.3
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ijbswa/}

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.privoxy.org/
COMMENT=	Web proxy with advanced filtering capabilities

.include "../../mk/bsd.prefs.mk"

PRIVOXY_USER?=		privoxy
PRIVOXY_GROUP?=		privoxy
BUILD_DEFS+=		PRIVOXY_USER PRIVOXY_GROUP

PKG_SYSCONFSUBDIR?=	privoxy

USE_PKGINSTALL=		YES
RCD_SCRIPTS=		privoxy
PKG_GROUPS=		${PRIVOXY_GROUP}
PKG_USERS=		${PRIVOXY_USER}:${PRIVOXY_GROUP}::Privoxy\ user

EGDIR=			${PREFIX}/share/examples/privoxy

CPPFLAGS+=		-Dunix

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}-stable

USE_TOOLS+=		autoconf213 gmake
MAKEFILE=		GNUmakefile

USE_TOOLS+=		perl

PTHREAD_AUTO_VARS=	yes
PTHREAD_OPTS+=		require

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${EGDIR}
CONFIGURE_ARGS+=	--with-user=${PRIVOXY_USER}
CONFIGURE_ARGS+=	--with-group=${PRIVOXY_GROUP}

USER_GROUP=		${PRIVOXY_USER} ${PRIVOXY_GROUP}

.for i in \
    config trust default.action standard.action user.action default.filter
CONF_FILES_PERMS+=	${EGDIR}/${i} ${PKG_SYSCONFDIR}/${i} ${USER_GROUP} 0660
.endfor

OWN_DIRS_PERMS+=	/var/log/privoxy ${USER_GROUP} 0775

DEINSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL
INSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL

FILES_SUBST+=		EGDIR=${EGDIR:Q}
FILES_SUBST+=		PRIVOXY_USER=${PRIVOXY_USER:Q}

pre-configure:
	@cd ${WRKSRC} &&					\
	(   autoheader && autoconf ;				\
	    ${MV} config config.bak &&				\
	    ${SED} ${FILES_SUBST_SED} <config.bak >config &&	\
	    ${RM} -f config.bak					\
	)

post-install:
	${CHOWN} -R ${ROOT_USER}:${ROOT_GROUP} ${EGDIR}
	${CHMOD} -R a+r ${EGDIR}

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
