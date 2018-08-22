# $NetBSD: Makefile,v 1.2 2018/08/22 09:47:54 wiz Exp $

DISTNAME=	Test-LWP-UserAgent-0.033
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-LWP-UserAgent/
COMMENT=	LWP::UserAgent suitable for simulating and testing network calls
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Path-Tiny-[0-9]*:../../filesystems/p5-Path-Tiny
DEPENDS+=	p5-Safe-Isa-[0-9]*:../../devel/p5-Safe-Isa
DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
DEPENDS+=	p5-Test-Needs-[0-9]*:../../devel/p5-Test-Needs
DEPENDS+=	p5-Test-RequiresInternet-[0-9]*:../../net/p5-Test-RequiresInternet
DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean

PERL5_PACKLIST=		auto/Test/LWP/UserAgent/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
