# New ports collection makefile for:	gtk
# Version required:			0.99.3
# Date created:				29 January 1998
# Whom:					bsieker@techfak.uni-bielefeld.de
#
# $NetBSD: Makefile,v 1.5 1998/03/10 16:33:33 frueauf Exp $

DISTNAME=	gtk+-0.99.3
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.gimp.org/pub/gtk/  \
		ftp://infosoc.uni-koeln.de/pub/ftp.gimp.org/pub/gtk/ \
		ftp://ftp.flirble.org/pub/X/gimp/pub/gtk/

MAINTAINER=	bsieker@techfak.uni-bielefeld.de

BUILD_DEPENDS=	${LOCALBASE}/bin/install-info:${PORTSDIR}/devel/gtexinfo

GNU_CONFIGURE=  yes
USE_X11=	yes

CFLAGS=		-pipe -O2

PLIST_SRC=	${WRKDIR:T}/.PLIST-src

pre-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' ${LOCALBASE}/info/dir > ${PREFIX}/info/dir; \
	 fi
	@${SED} -e 's|\$${LOCALBASE}|'${LOCALBASE}'|g' < ${PKGDIR}/PLIST > ${PLIST_SRC}

.include <bsd.port.mk>
