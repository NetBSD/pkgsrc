# New ports collection makefile for:	lesstif
# Version required:	0.83
# Date created:		December 10, 1996
# Whom:			1wardd@airmail.net
#
# $NetBSD: Makefile,v 1.13 1998/03/23 20:36:04 frueauf Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/08 08:34:13 tg Exp
#

DISTNAME=	lesstif-0.83
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.lesstif.org/pub/hungry/lesstif/srcdist/ \
		ftp://ftp.hungry.com/pub/hungry/lesstif/srcdist/

MAINTAINER=	packages@netbsd.org

GNU_CONFIGURE=  yes
USE_X11=	yes
# change this for debugging
CONFIGURE_ENV=	CCFLAGS="-O -pipe" INSTALL_SCRIPT="${INSTALL_SCRIPT}"

# this is worst case, when you're about to overwrite real Motif with Lesstif
IS_INTERACTIVE=	yes

MAN1=		mwm.1
MAN5=		mwmrc.5

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
	${LDCONFIG} || ${TRUE}

.include <bsd.port.mk>
