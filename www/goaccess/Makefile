# $NetBSD: Makefile,v 1.2 2014/02/22 14:27:43 wiedi Exp $

DISTNAME=	goaccess-0.7.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=goaccess/}

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	http://goaccess.prosoftcorp.com/
COMMENT=	Real-time web log analyzer
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

USE_TOOLS+=     pkg-config
USE_NCURSES=	yes

LIBS.SunOS+=	-lsocket -lnsl
CPPFLAGS.SunOS+=	-D__EXTENSIONS__

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
