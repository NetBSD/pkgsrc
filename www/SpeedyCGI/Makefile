# $NetBSD: Makefile,v 1.1.1.1 2004/06/22 21:34:50 adrianp Exp $

DISTNAME=	CGI-SpeedyCGI-2.22
PKGNAME=	SpeedyCGI-2.22
CATEGORIES=	www
MASTER_SITES=	http://daemoninc.com/SpeedyCGI/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://daemoninc.com/speedycgi/
COMMENT=	Speed up perl scripts by running them persistently

USE_PERL5=	YES

USE_BUILDLINK3= YES
PERL5_PACKLIST= ${PERL5_SITEARCH}/auto/CGI/SpeedyCGI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
