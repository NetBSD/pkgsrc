# $NetBSD: Makefile,v 1.8 2013/11/13 15:59:22 is Exp $
#

DISTNAME=		yaws-1.97
CATEGORIES=		www
MASTER_SITES=		http://yaws.hyber.org/download/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://yaws.hyber.org/
COMMENT=		High perfomance HTTP 1.1 webserver written in Erlang
LICENSE=		modified-bsd

BUILD_DEFS+=		VARBASE

USE_TOOLS+=		gmake perl pax autoconf
GNU_CONFIGURE=		yes
AUTOCONF_REQD=		2.50

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}/yaws
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-extrainclude=${PAMBASE}/include/security

EGDIR=			${PREFIX}/share/examples/yaws
CONF_FILES=		${EGDIR}/yaws.conf ${PKG_SYSCONFDIR}/yaws/yaws.conf
RCD_SCRIPTS=		yaws
RCD_SCRIPT_SRC.yaws=	${WRKSRC}/scripts/netbsd/yaws.sh

LIBDIR=			${PREFIX}/lib/yaws
WWWDIR=			${PREFIX}/share/yaws/www
INSTALLATION_DIRS=	${EGDIR}
INSTALLATION_DIRS+=	${LIBDIR}/ebin ${LIBDIR}/include
INSTALLATION_DIRS+=	${LIBDIR}/priv ${WWWDIR}

OWN_DIRS=		${VARBASE}/log/yaws

REPLACE_PYTHON=		www/cgi-bin/foo.py
#CHECK_INTERPRETER_SKIP=	${WWWDIR}/cgi-bin/foo.py
CHECK_INTERPRETER_SKIP=	share/yaws/www/cgi-bin/foo.py

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	${PKGMANDIR}/man5

post-patch:
	${RM} ${WRKDIR}/yaws
	${RM} -Rf ${WRKSRC}/www/.xvpics
	${RM} -Rf ${WRKSRC}/www/testdir
	${FIND} ${WRKSRC} -name \*.orig -o -name .empty | ${XARGS} ${RM} -f

pre-configure:
	cd ${WRKSRC} && autoconf

post-configure:
	${SED} -e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g" \
		-e "s|@PREFIX@|${PREFIX}|g" \
		-e "s|@VARBASE@|${VARBASE}|g" \
		${FILESDIR}/yaws.conf > ${WRKDIR}/yaws.conf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/yaws ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/yaws.conf ${DESTDIR}${EGDIR}

	${INSTALL_DATA} ${WRKSRC}/ebin/* ${DESTDIR}${LIBDIR}/ebin
	${INSTALL_DATA} ${WRKSRC}/include/* ${DESTDIR}${LIBDIR}/include
	cd ${WRKSRC}/priv && pax -rw . ${DESTDIR}${LIBDIR}/priv

	cd ${WRKSRC}/www && pax -rw . ${DESTDIR}${WWWDIR}

	${INSTALL_MAN} ${WRKSRC}/man/yaws.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/man/*.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5

	${INSTALL_DATA_DIR} ${DESTDIR}${PKG_SYSCONFDIR}/yaws

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
