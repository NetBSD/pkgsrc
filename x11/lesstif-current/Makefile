# $NetBSD: Makefile,v 1.13 1998/08/12 22:44:21 frueauf Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/08 08:34:13 tg Exp
#

DISTNAME=	lesstif-current
PKGNAME=	lesstif-19980510
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	packages@netbsd.org

CONFLICTS=	lesstif-0.82 lesstif-0.83 lesstif-0.84 lesstif-0.85 \
		lesstif-0.85.2 lesstif-0.85.3 lesstif-0.86.0

MIRROR_DISTFILE= no
GNU_CONFIGURE=  yes
USE_LIBTOOL=	yes
USE_X11=	yes
# change this for debugging
CONFIGURE_ENV=	CCFLAGS="-O -pipe" INSTALL_SCRIPT="${INSTALL_SCRIPT}"

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
