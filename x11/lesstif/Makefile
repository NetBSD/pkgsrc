# $NetBSD: Makefile,v 1.26 1998/07/17 17:18:49 tv Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/08 08:34:13 tg Exp
#

DISTNAME=	lesstif-0.85.3
CATEGORIES=	x11
MASTER_SITES=	ftp://linux.gt.ed.net/pub/linux/libs/lesstif/srcdist/ \
		ftp://ftp.mathematik.th-darmstadt.de/pub/linux/mirrors/misc/lesstif/srcdist/ \
		ftp://ftp.lesstif.org/pub/hungry/lesstif/srcdist/

MAINTAINER=	packages@netbsd.org

BUILD_DEPENDS=	${PREFIX}/bin/libtool:../../devel/libtool

CONFLICTS=	lesstif-0.82 lesstif-0.83 lesstif-0.84 lesstif-0.85 \
		lesstif-19980510 lesstif-0.85.2

GNU_CONFIGURE=  yes
USE_X11=	yes

# disable this for debugging
CONFIGURE_ARGS+=--enable-production

CONFIGURE_ENV=	CCFLAGS="-O -pipe" INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		VarHaveMan2html=0 LIBTOOL=${PREFIX}/bin/libtool

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
