# $NetBSD: Makefile,v 1.26 2019/08/11 13:24:16 wiz Exp $

DISTNAME=	CGI-SpeedyCGI-2.22
PKGNAME=	SpeedyCGI-2.22
PKGREVISION=	13
CATEGORIES=	www
MASTER_SITES=	http://daemoninc.com/SpeedyCGI/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://daemoninc.com/SpeedyCGI/
COMMENT=	Speed up perl scripts by running them persistently

MAKE_JOBS_SAFE=		no

PERL5_PACKLIST= 	auto/CGI/SpeedyCGI/.packlist

# XXX Kick can down the road and hope the developer fixes this issue.
MAKE_ENV+=		PERL_USE_UNSAFE_INC=1

SUBST_CLASSES+=		run
SUBST_STAGE.run=	pre-configure
SUBST_FILES.run=	src/optdefs
SUBST_SED.run+=		-e "s|@@PREFIX@@|${PREFIX}|g"
SUBST_MESSAGE.run=	Fixing hardcoded paths.

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
