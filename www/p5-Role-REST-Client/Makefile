# $NetBSD: Makefile,v 1.3 2017/06/05 14:25:30 ryoon Exp $

DISTNAME=	Role-REST-Client-0.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KA/KAARE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Role-REST-Client
COMMENT=	REST Client Role
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Data-Serializer-[0-9]*:../../devel/p5-Data-Serializer
DEPENDS+=	p5-MooX-HandlesVia>=0.001004:../../devel/p5-MooX-HandlesVia
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
DEPENDS+=	p5-Type-Tiny>=0.024:../../devel/p5-Type-Tiny
DEPENDS+=	p5-HTTP-Thin-[0-9]*:../../www/p5-HTTP-Thin
DEPENDS+=	p5-URI-Escape-XS>=0.11:../../www/p5-URI-Escape-XS
DEPENDS+=	p5-Moo>=1.003000:../../devel/p5-Moo
DEPENDS+=	p5-JSON>=2.00:../../converters/p5-JSON

PERL5_PACKLIST=	auto/Role/REST/Client/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
