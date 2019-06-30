# $NetBSD: Makefile,v 1.13 2019/06/30 20:17:19 nia Exp $

DISTNAME=	AnyEvent-ReverseHTTP-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AnyEvent/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/AnyEvent-ReverseHTTP
COMMENT=	Perl 5 module providing reversehttp for AnyEvent
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/AnyEvent/ReverseHTTP/.packlist

DEPENDS+=	p5-Any-Moose-[0-9]*:../../devel/p5-Any-Moose
DEPENDS+=	p5-AnyEvent-[0-9]*:../../devel/p5-AnyEvent
DEPENDS+=	p5-AnyEvent-HTTP-[0-9]*:../../www/p5-AnyEvent-HTTP
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
