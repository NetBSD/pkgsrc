# $NetBSD: Makefile,v 1.2 1999/12/16 14:59:12 bouyer Exp $
# FreeBSD Id: ports/textproc/textutils/Makefile,v 1.7 1999/09/18 17:46:30 steve Exp

DISTNAME=	textutils-2.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=textutils/}

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/textutils/textutils.html

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--program-prefix=g

USE_GMAKE=	yes

post-install:
	install-info ${PREFIX}/info/textutils.info ${PREFIX}/info/dir

.include "../../mk/bsd.pkg.mk"
