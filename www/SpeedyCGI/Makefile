# $NetBSD: Makefile,v 1.3 2005/07/13 18:01:45 jlam Exp $

DISTNAME=	CGI-SpeedyCGI-2.22
PKGNAME=	SpeedyCGI-2.22
CATEGORIES=	www
MASTER_SITES=	http://daemoninc.com/SpeedyCGI/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://daemoninc.com/speedycgi/
COMMENT=	Speed up perl scripts by running them persistently

USE_PERL5=	YES

PERL5_PACKLIST= auto/CGI/SpeedyCGI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
