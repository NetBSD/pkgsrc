# $NetBSD: Makefile,v 1.4 2020/09/08 13:16:46 wiz Exp $

DISTNAME=	HTTP-Tiny-Mech-1.001002
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KE/KENTNL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/HTTP::Tiny::Mech
COMMENT=	Wrap a WWW::Mechanize instance in an HTTP::Tiny compatible interface
LICENSE=	${PERL5_LICENSE}


PERL5_PACKLIST=	auto/HTTP/Tiny/Mech/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
