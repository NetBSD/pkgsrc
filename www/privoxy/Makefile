# $NetBSD: Makefile,v 1.11 2004/10/03 00:18:27 tv Exp $
#

DISTNAME=	${PKGNAME_NOREV}-stable-src
PKGNAME=	privoxy-3.0.3
PKGREVISION=	2
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
PKG_USERS=		${PRIVOXY_USER}:${PRIVOXY_GROUP}::Privoxy\\ user

EGDIR=			${PREFIX}/share/examples/privoxy

AUTOCONF_REQD=		2.13
CPPFLAGS+=		-Dunix

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}-stable
USE_BUILDLINK3=		YES

USE_GNU_TOOLS+=		make
MAKEFILE=		GNUmakefile

USE_PERL5=		build

PTHREAD_OPTS+=		require

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--localstatedir=/var
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

FILES_SUBST+=		EGDIR=${EGDIR}
FILES_SUBST+=		PRIVOXY_USER=${PRIVOXY_USER}

pre-configure:
	@cd ${WRKSRC} &&					\
	(   ${AUTOHEADER} && ${AUTOCONF} ;			\
	    ${MV} config config.bak &&				\
	    ${SED} ${FILES_SUBST_SED} <config.bak >config &&	\
	    ${RM} -f config.bak					\
	)

post-install:
	${CHOWN} -R ${ROOT_USER}:${ROOT_GROUP} ${EGDIR}
	${CHMOD} -R a+r ${EGDIR}

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
