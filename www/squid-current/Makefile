# $NetBSD: Makefile,v 1.8 1999/02/19 16:08:45 christos Exp $
#

DISTNAME=	squid-2.1.PATCH2
CATEGORIES=	www
MASTER_SITES=  \
	ftp://squid.nlanr.net/pub/squid-2/STABLE/ \
	ftp://ftp.gw.com/pub/unix/squid/squid-2/STABLE/ \
	ftp://ftp.funet.fi/pub/mirrors/squid.nlanr.net/pub/squid-2/STABLE/ \
	ftp://www.unimelb.edu.au/pub/cwis/servers/unix/squid/squid-2/STABLE/ \
	ftp://sunsite.auc.dk/pub/infosystems/squid/squid-2/STABLE/ \
	ftp://ftp.net.lut.ac.uk/squid/squid-2/STABLE/
EXTRACT_SUFX=	-src.tar.gz

PATCH_SITES= \
	http://squid.nlanr.net/Squid/v2/2.1/ \
	http://mirror.aarnet.edu.au/squid/v2/2.1/
PATCHFILES=squid-2.1.PATCH2-clientHandleIMSReply-leak.patch

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://squid.nlanr.net/Squid/

CONFLICTS=	squid-1.1.21 \
		squid-2.0.PRE1 \
		squid-2.0.RELEASE \
		squid-2.0.PATCH1 \
		squid-2.0.PATCH2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=/etc \
		--localstatedir=/var/squid

# Options you might want to enable
CONFIGURE_ARGS+=	--enable-cachemgr-hostname=localhost
CONFIGURE_ARGS+=	--enable-icmp
#CONFIGURE_ARGS+=	--enable-snmp
CONFIGURE_ARGS+=	--enable-cache-digests

MAKEFILE=	makefile
MAKE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" PKG_PREFIX="${PREFIX}"

post-build:
	${SED} s#@PREFIX@#${PREFIX}#g <${FILESDIR}/squid.sh >${WRKDIR}/squid.sh

PLIST_SRC=	${PKGDIR}/PLIST ${WRKDIR}/PLIST.share

pre-install:
	@-rm -f ${WRKDIR}/PLIST.share
	@${MKDIR} ${PREFIX}/share/squid
	@${MKDIR} ${PREFIX}/share/squid/errors
	@${MKDIR} ${PREFIX}/share/squid/icons
	@(							\
	cd ${WRKSRC}/errors/English;				\
	ls ERR_* | ${SED} -e 's@^@share/squid/errors/@';		\
	${ECHO} "@dirrm share/squid/errors";			\
	cd ${WRKSRC}/icons;					\
	ls anthony-*.gif | ${SED} -e 's@^@share/squid/icons/@';	\
	${ECHO} "@dirrm share/squid/icons";			\
	${ECHO} "share/squid/mib.txt";				\
	${ECHO} "share/squid/mime.conf";				\
	${ECHO} "share/squid/mime.conf.default";			\
	${ECHO} "share/squid/squid.conf.default";			\
	${ECHO} "@dirrm share/squid";				\
	) > ${WRKDIR}/PLIST.share

post-install:
	cd ${WRKSRC}/src; make install-pinger
	${INSTALL_SCRIPT} ${WRKDIR}/squid.sh ${PREFIX}/etc/rc.d/squid.sh
	@${SETENV} ${MAKE_ENV} ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <../../mk/bsd.pkg.mk>
