# $NetBSD: Makefile,v 1.3 1998/08/20 15:17:31 tsarna Exp $
# $FreeBSD Id: Makefile,v 1.36 1998/03/20 13:58:54 peter Exp
#

DISTNAME=	squid-1.1.21
CATEGORIES=	www
MASTER_SITES=  \
	ftp://squid.nlanr.net/pub/squid-1.1/ \
	ftp://www.unimelb.edu.au/pub/cwis/servers/unix/squid/squid-1.1/ \
	ftp://sunsite.auc.dk/pub/infosystems/squid/squid-1.1/ \
	ftp://ftp.net.lut.ac.uk/squid/squid-1.1/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://squid.nlanr.net/Squid/

GNU_CONFIGURE=	yes
# Follow the apache port's lead...
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/squid --bindir=${PREFIX}/sbin \
		--libexecdir=${PREFIX}/sbin --localstatedir=/var/squid
MAKEFILE=	makefile

MAKE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"
# If you need to set any of these options, read the source and uncomment
# these if appropriate.
#MAKE_ENV+=	HOST_OPT="-DCACHEMGR_HOSTNAME=\"getfullhostname()\""
#MAKE_ENV+=	AUTH_OPT="-DUSE_PROXY_AUTH=1"
#MAKE_ENV+=	LOG_HDRS_OPT="-DLOG_FULL_HEADERS=1"
#MAKE_ENV+=	ICMP_OPT="-DUSE_ICMP=1"
#MAKE_ENV+=	DELAY_HACK="-DDELAY_HACK=1"
#MAKE_ENV+=	USERAGENT_OPT="-DUSE_USERAGENT_LOG=1"
#MAKE_ENV+=	KILL_PARENT_OPT="-DKILL_PARENT_OPT"
#MAKE_ENV+=	USE_POLL_OPT="-DUSE_POLL"
# do NOT define both USE_SPLAY_TREE and USE_BIN_TREE at the same time!
#MAKE_ENV+=	USE_SPLAY_TREE="-DUSE_SPLAY_TREE"
#MAKE_ENV+=	USE_BIN_TREE="-DUSE_BIN_TREE"
#MAKE_ENV+=	RELOAD_INTO_IMS="-DRELOAD_INTO_IMS"
#MAKE_ENV+=	UNDERSCORES_OPT="-DALLOW_HOSTNAME_UNDERSCORES"

post-build:
	${SED} s#@PREFIX@#${PREFIX}#g <${FILESDIR}/squid.sh >${WRKDIR}/squid.sh

post-install:
	cd ${WRKSRC}/src; make install-pinger
	${INSTALL_SCRIPT} ${WRKDIR}/squid.sh ${PREFIX}/etc/rc.d/squid.sh
	@${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <../../mk/bsd.pkg.mk>
