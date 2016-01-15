# $NetBSD: Makefile,v 1.11 2016/01/15 10:53:57 wen Exp $

DISTNAME=	Time-Warp-0.52
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5 time
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Time-Warp/
COMMENT=	Perl 5 module to control the flow of time
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Time/Warp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
