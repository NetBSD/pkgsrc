# $NetBSD: Makefile,v 1.4 1998/12/06 12:42:00 tron Exp $
#

DISTNAME=	squid-2.0.PATCH2
CATEGORIES=	www
MASTER_SITES=  \
	ftp://squid.nlanr.net/pub/squid-2/ \
	ftp://ftp.gw.com/pub/unix/squid/squid-2/ \
	ftp://ftp.funet.fi/pub/mirrors/squid.nlanr.net/pub/squid-2/ \
	ftp://www.unimelb.edu.au/pub/cwis/servers/unix/squid/squid-2/ \
	ftp://sunsite.auc.dk/pub/infosystems/squid/squid-2/ \
	ftp://ftp.net.lut.ac.uk/squid/squid-2/
EXTRACT_SUFX=	-src.tar.gz

CONFLICTS=	squid-1.1.21 \
		squid-2.0.PRE1 \
		squid-2.0.RELEASE \
		squid-2.0.PATCH1

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://squid.nlanr.net/Squid/

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=/etc \
		--localstatedir=/var/squid

# Options you might want to enable
CONFIGURE_ARGS+=	--enable-cachemgr-hostname=localhost
CONFIGURE_ARGS+=	--enable-icmp
#CONFIGURE_ARGS+=	--enable-snmp

MAKEFILE=	makefile
MAKE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

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
	ls ERR_* | sed -e 's@^@share/squid/errors/@';		\
	echo "@dirrm share/squid/errors";			\
	cd ${WRKSRC}/icons;					\
	ls anthony-*.gif | sed -e 's@^@share/squid/icons/@';	\
	echo "@dirrm share/squid/icons";			\
	echo "share/squid/mib.txt";				\
	echo "share/squid/mime.conf";				\
	echo "share/squid/mime.conf.default";			\
	echo "share/squid/squid.conf.default";			\
	echo "@dirrm share/squid";				\
	) > ${WRKDIR}/PLIST.share

# This is GNU ${datadir}/squid/squid.conf
DEFCONF=	${PREFIX}/share/squid/squid.conf.default

post-install:
	cd ${WRKSRC}/src; make install-pinger
	${INSTALL_SCRIPT} ${WRKDIR}/squid.sh ${PREFIX}/etc/rc.d/squid.sh
	@${SH} ${PKGDIR}/INSTALL ${PKGNAME} ${DEFCONF} POST-INSTALL

.include <../../mk/bsd.pkg.mk>
