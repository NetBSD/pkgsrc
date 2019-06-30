# $NetBSD: Makefile,v 1.7 2019/06/30 20:17:42 nia Exp $

DISTNAME=	Role-REST-Client-0.23
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KA/KAARE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Role-REST-Client
COMMENT=	REST Client Role
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Data-Serializer-[0-9]*:../../devel/p5-Data-Serializer
DEPENDS+=	p5-MooX-HandlesVia>=0.001004:../../devel/p5-MooX-HandlesVia
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
DEPENDS+=	p5-Type-Tiny>=0.024:../../devel/p5-Type-Tiny
DEPENDS+=	p5-HTTP-Thin-[0-9]*:../../www/p5-HTTP-Thin
DEPENDS+=	p5-URI-Escape-XS>=0.11:../../www/p5-URI-Escape-XS
DEPENDS+=	p5-Moo>=1.003000:../../devel/p5-Moo
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack
DEPENDS+=	p5-JSON>=2.00:../../converters/p5-JSON
DEPENDS+=	p5-JSON-MaybeXS-[0-9]*:../../converters/p5-JSON-MaybeXS
DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML
DEPENDS+=	p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple

BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-TCP-[0-9]*:../../net/p5-Test-TCP
BUILD_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings

PERL5_PACKLIST=	auto/Role/REST/Client/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
