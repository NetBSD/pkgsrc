# $NetBSD: Makefile,v 1.17 2018/08/22 09:48:00 wiz Exp $
#

DISTNAME=		yaws-2.0.6
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		http://yaws.hyber.org/download/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://yaws.hyber.org/
COMMENT=		High perfomance HTTP 1.1 webserver written in Erlang
LICENSE=		modified-bsd

BUILD_DEFS+=		VARBASE

USE_TOOLS+=		gmake perl tar
GNU_CONFIGURE=		yes

PKG_SYSCONFSUBDIR=	yaws

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-extrainclude=${PAMBASE}/include/security
CONFIGURE_ARGS+=	ERLANG_INSTALL_LIB_DIR_yaws=${PREFIX}/lib/yaws
CONFIGURE_ARGS+=	wwwdir=${WWWDIR}

# Not compatible with SunOS PAM headers
.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--disable-pam
.endif

EGDIR=			${PREFIX}/share/examples/yaws
CONF_FILES=		${EGDIR}/yaws.conf ${PKG_SYSCONFDIR}/yaws.conf
RCD_SCRIPTS=		yaws
RCD_SCRIPT_SRC.yaws=	${WRKSRC}/scripts/netbsd/yaws.sh

WWWDIR=			${PREFIX}/share/yaws/www

OWN_DIRS=		${VARBASE}/log/yaws

REPLACE_PYTHON=		www/cgi-bin/foo.py
CHECK_INTERPRETER_SKIP=	share/yaws/www/cgi-bin/foo.py

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples

FILES_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

post-extract:
	cd ${WRKSRC} && ${CHMOD} -R g-w www
	${RM} -Rf ${WRKSRC}/www/testdir

post-configure:
	${SED} -e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g" \
		-e "s|@PREFIX@|${PREFIX}|g" \
		-e "s|@VARBASE@|${VARBASE}|g" \
		${FILESDIR}/yaws.conf > ${WRKDIR}/yaws.conf

post-install:
	${RM} -f ${DESTDIR}${WWWDIR}/code/Makefile*
	${RM} -f ${DESTDIR}${WWWDIR}/shoppingcart/Makefile*

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
