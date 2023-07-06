# $NetBSD: Makefile,v 1.16 2023/07/06 09:42:09 wiz Exp $

DISTNAME=	Date-Extract-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Date-Extract
COMMENT=	Perl 5 module to extract probable dates from strings
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime-Format-Natural-[0-9]*:../../time/p5-DateTime-Format-Natural
DEPENDS+=	p5-Class-Data-Inheritable-[0-9]*:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-DateTime>=0:../../time/p5-DateTime

TEST_DEPENDS+=	p5-Test-MockTime-HiRes-[0-9]*:../../time/p5-Test-MockTime-HiRes

PERL5_PACKLIST=	auto/Date/Extract/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
