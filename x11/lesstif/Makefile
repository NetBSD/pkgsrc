# New ports collection makefile for:	lesstif
# Version required:	0.82
# Date created:		December 10, 1996
# Whom:			1wardd@airmail.net
#
# $NetBSD: Makefile,v 1.7 1998/02/02 08:11:05 hubertf Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/08 08:34:13 tg Exp
#

DISTNAME=	lesstif-0.82
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.lesstif.org/pub/hungry/lesstif/  \
		ftp://ftp.hungry.com/pub/hungry/lesstif/

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=  yes
USE_X11=	yes
# change this and remove the strip statement in post-install for debugging
CONFIGURE_ENV=	CCFLAGS="-O -pipe"

# this is worst case, when you're about to overwrite real Motif with Lesstif
IS_INTERACTIVE=	yes

pre-fetch:
	@if [ -d ${X11BASE}/include/Xm ]; then \
		if [ -d ${X11BASE}/lib/X11/lesstif ]; then \
			${ECHO} "Upgrading a previous Lesstif installation"; \
			return 0; \
		fi; \
		${ECHO} "***********************************************************"; \
		${ECHO} "*                      W a r n i n g                      *"; \
		${ECHO} "* This port will overwrite your Motif installation.       *"; \
		${ECHO} "***********************************************************"; \
		${ECHO} -n "Is this ok? (y/n) ==> "; \
		(read ans; \
		  case x"$$ans" in \
		    xy*|xY*) \
			return 0; \
			;; \
		    *) \
			${ECHO} "Okay, I won't install it then...."; \
			${ECHO} "(Don't worry about the following \"*** Error code 1\"s)"; \
			return 1; \
			;; \
		  esac) \
	fi

post-install:
	${MKDIR} ${PREFIX}/lib/X11/mwm ${PREFIX}/lib/X11/app-defaults
	${INSTALL_DATA} ${WRKSRC}/clients/Motif-1.2/mwm/system.mwmrc \
		${PREFIX}/lib/X11/mwm
	${INSTALL_DATA} ${WRKSRC}/clients/Motif-1.2/mwm/alt.map ${PREFIX}/lib/X11/mwm
	${INSTALL_DATA} ${WRKSRC}/clients/Motif-1.2/mwm/Mwm \
		${PREFIX}/lib/X11/app-defaults/Mwm
	/usr/bin/strip ${PREFIX}/lib/libXm.so.0.1 ${PREFIX}/lib/libMrm.so.0.1
	${LDCONFIG} -m ${PREFIX}/lib || ${TRUE}

.include <bsd.port.mk>
