# $NetBSD: Makefile,v 1.11 2002/07/24 19:45:28 jlam Exp $
# FreeBSD Id: ports/textproc/textutils/Makefile,v 1.7 1999/09/18 17:46:30 steve Exp

DISTNAME=	textutils-2.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=textutils/}

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/textutils/textutils.html
COMMENT=	GNU text utilities

USE_PERL5=	build
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--program-prefix=g

post-install:
	${INSTALL_INFO} ${PREFIX}/info/textutils.info ${PREFIX}/info/dir

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
