# $NetBSD: Makefile,v 1.43 1999/11/15 21:30:27 drochner Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/08 08:34:13 tg Exp
#

DISTNAME=		lesstif-0.89.4
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.hungry.com/pub/hungry/lesstif/srcdist/ \
			ftp://ftp.unicamp.br/pub/X11/lesstif/srcdist/ \
			ftp://ftp.kddlabs.co.jp/X11/lesstif/srcdist/ \
			ftp://linux.mathematik.tu-darmstadt.de/pub/linux/mirrors/misc/lesstif/srcdist/ \
			http://gd.tuwien.ac.at/hci/lesstif/srcdist/ \
			http://www.damtp.cam.ac.uk/mirror/ftp.hungry.com/pub/hungry/lesstif/srcdist/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.lesstif.org/

USE_LIBTOOL=		yes
USE_X11BASE=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-build-12	# needed for www/Mosaic
CONFIGURE_ARGS+=	--enable-build-20 --enable-default-20 \
			--enable-production --disable-debug

.include "../../mk/bsd.pkg.mk"
