# $NetBSD: Makefile,v 1.5 2001/01/13 16:10:55 tron Exp $
# FreeBSD Id: ports/textproc/textutils/Makefile,v 1.7 1999/09/18 17:46:30 steve Exp

DISTNAME=	textutils-2.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=textutils/}

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/textutils/textutils.html

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--program-prefix=g

PLIST_SUBST+=	LOCALEBASE="${LOCALEBASE}"

post-install:
	install-info ${PREFIX}/info/textutils.info ${PREFIX}/info/dir

.include "../../mk/bsd.pkg.mk"
