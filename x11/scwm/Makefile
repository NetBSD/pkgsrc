# $NetBSD: Makefile,v 1.3 1999/08/29 21:50:21 jlam Exp $
#

DISTNAME=	scwm-0.9
CATEGORIES=	x11
MASTER_SITES=	ftp://scwm.mit.edu/pub/scwm/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://scwm.mit.edu/

DEPENDS+=	guile-1.3.2:../../lang/guile
DEPENDS+=	gtk+-1.2.4:../../x11/gtk

CONFIGURE_ARGS+=	--with-guile-prefix=${LOCALBASE}	\
			--with-gtk-prefix=${X11BASE}		\
			--enable-multibyte

USE_X11BASE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
