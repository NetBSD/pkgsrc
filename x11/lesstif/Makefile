# $NetBSD: Makefile,v 1.17 1998/05/15 14:44:07 agc Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/08 08:34:13 tg Exp
#

DISTNAME=	lesstif-0.83
CATEGORIES=	x11
MASTER_SITES=	ftp://linux.gt.ed.net/pub/linux/libs/lesstif/srcdist/ \
		ftp://ftp.mathematik.th-darmstadt.de/pub/linux/mirrors/misc/lesstif/srcdist/ \
		ftp://ftp.lesstif.org/pub/hungry/lesstif/srcdist/

MAINTAINER=	packages@netbsd.org

GNU_CONFIGURE=  yes
USE_X11=	yes
# change this for debugging
CONFIGURE_ENV=	CCFLAGS="-O -pipe" INSTALL_SCRIPT="${INSTALL_SCRIPT}"

MAN1=		mwm.1
MAN5=		mwmrc.5

pre-fetch:
	@if [ -d ${X11BASE}/include/Xm ]; then 				\
		if [ -d ${X11BASE}/lib/X11/lesstif ]; then 		\
			${ECHO} "Upgrading a previous Lesstif installation"; \
			return 0; 					\
		fi; 							\
		${ECHO} "Motif is already installed in ${X11BASE}";	\
		${ECHO} "To install lesstif, first delete Motif from ${X11BASE}"; \
		return 1;						\
	fi

post-install:
	${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
