# $NetBSD: Makefile,v 1.50 2000/06/21 05:31:43 jlam Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/08 08:34:13 tg Exp
#

DISTNAME=		lesstif-0.91.0
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.hungry.com/pub/hungry/lesstif/srcdist/ \
			ftp://ftp.unicamp.br/pub/X11/lesstif/srcdist/ \
			ftp://ftp.kddlabs.co.jp/X11/lesstif/srcdist/ \
			ftp://linux.mathematik.tu-darmstadt.de/pub/linux/mirrors/misc/lesstif/srcdist/ \
			http://gd.tuwien.ac.at/hci/lesstif/srcdist/ \
			http://www.damtp.cam.ac.uk/mirror/ftp.hungry.com/pub/hungry/lesstif/srcdist/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.lesstif.org/

BUILD_DEPENDS+=		lynx:../../www/lynx

USE_X11BASE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig \
			${WRKSRC}/Xlt/ltconfig \
			${WRKSRC}/Xbae/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--enable-build-12	# needed for www/Mosaic
CONFIGURE_ARGS+=	--enable-build-20 --enable-default-20 \
			--enable-production --disable-debug
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/ac_find_motif.m4 \
		${LOCALBASE}/share/aclocal/ac_find_motif.m4

.include "../../mk/bsd.pkg.mk"
