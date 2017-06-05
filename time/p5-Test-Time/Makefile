# $NetBSD: Makefile,v 1.5 2017/06/05 14:25:05 ryoon Exp $

DISTNAME=	Test-Time-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~satoh/Test-Time/
COMMENT=	Override time()/sleep() core functions for testing
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp

PERL5_PACKLIST=	auto/Test/Time/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
