# $NetBSD: Makefile,v 1.34 1999/01/12 23:17:34 frueauf Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/08 08:34:13 tg Exp
#

DISTNAME=	lesstif-0.87.1
CATEGORIES=	x11
MASTER_SITES=	ftp://linux.gt.ed.net/pub/linux/libs/lesstif/srcdist/ \
		ftp://ftp.mathematik.th-darmstadt.de/pub/linux/mirrors/misc/lesstif/srcdist/ \
		ftp://ftp.lesstif.org/pub/hungry/lesstif/srcdist/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.lesstif.org/

CONFLICTS=	lesstif-*

GNU_CONFIGURE=  yes
USE_LIBTOOL=	yes
USE_X11=	yes

# disable this for debugging
CONFIGURE_ARGS+=--enable-production

CONFIGURE_ENV=	CCFLAGS="-O -pipe" INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		VarHaveMan2html=0

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

.include "../../mk/bsd.pkg.mk"
