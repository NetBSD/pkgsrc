# $NetBSD: Makefile,v 1.9 2001/12/30 11:52:13 wiz Exp $
# FreeBSD Id: ports/textproc/textutils/Makefile,v 1.7 1999/09/18 17:46:30 steve Exp

DISTNAME=	textutils-2.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=textutils/}

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/textutils/textutils.html
COMMENT=	GNU text utilities

BUILD_DEPENDS+=	perl>=${PERL5_REQD}:../../lang/perl5

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--program-prefix=g

post-install:
	install-info ${PREFIX}/info/textutils.info ${PREFIX}/info/dir

.include "../../mk/bsd.pkg.mk"
