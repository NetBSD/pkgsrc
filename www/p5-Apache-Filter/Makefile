# $NetBSD: Makefile,v 1.5 2003/06/02 01:16:05 jschauma Exp $

DISTNAME=	Apache-Filter-1.019
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5afi
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	perl5 module to alter the output of previous Apache handlers

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/Filter/.packlist

.include "../../www/ap-perl/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
