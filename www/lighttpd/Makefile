# $NetBSD: Makefile,v 1.29 2011/11/30 11:13:59 drochner Exp $

DISTNAME=	lighttpd-1.4.29
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://download.lighttpd.net/lighttpd/releases-1.4.x/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.lighttpd.net/
COMMENT=	Fast, light-footprint HTTP server
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
SHLIBTOOL_OVERRIDE=	# empty
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/${PKGBASE}
CONFIGURE_ARGS+=	--with-pcre

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

INSTALLATION_DIRS=	${DOCDIR} ${EGDIR} ${EGDIR}/conf.d ${EGDIR}/vhosts.d
OWN_DIRS=		${PKG_SYSCONFDIR}/conf.d
OWN_DIRS+=		${PKG_SYSCONFDIR}/vhosts.d

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
