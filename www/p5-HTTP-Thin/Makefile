# $NetBSD: Makefile,v 1.5 2019/08/11 13:24:47 wiz Exp $

DISTNAME=	HTTP-Thin-0.006
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PE/PERIGRIN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-Thin
COMMENT=	Thin Wrapper around HTTP::Tiny to play nice with HTTP::Message
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Method-Modifiers-[0-9]*:../../devel/p5-Class-Method-Modifiers
DEPENDS+=	p5-Hash-MultiValue-[0-9]*:../../devel/p5-Hash-MultiValue
DEPENDS+=	p5-Safe-Isa-[0-9]*:../../devel/p5-Safe-Isa
DEPENDS+=	p5-HTTP-Message-[0-9]*:../../www/p5-HTTP-Message
DEPENDS+=	p5-HTTP-Tiny-[0-9]*:../../www/p5-HTTP-Tiny

PERL5_PACKLIST=	auto/HTTP/Thin/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
