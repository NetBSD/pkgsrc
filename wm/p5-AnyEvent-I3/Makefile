# $NetBSD: Makefile,v 1.1 2024/11/20 13:13:05 wiz Exp $

DISTNAME=	AnyEvent-I3-0.19
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	wm devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MS/MSTPLBG/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/AnyEvent::I3
COMMENT=	Perl module to communicate with the i3 window manager
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	i3-[0-9]*:../../wm/i3

PERL5_PACKLIST=	auto/AnyEvent/I3/.packlist

DEPENDS+=	p5-AnyEvent-[0-9]*:../../devel/p5-AnyEvent
DEPENDS+=	p5-JSON-XS-[0-9]*:../../converters/p5-JSON-XS

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
