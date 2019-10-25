# $NetBSD: Makefile,v 1.1 2019/10/25 13:43:45 mef Exp $

DISTNAME=	HTTP-Tiny-Mech-1.001002
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/K/KE/KENTNL/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/HTTP::Tiny::Mech
COMMENT=	Wrap a WWW::Mechanize instance in an HTTP::Tiny compatible interface
LICENSE=	${PERL5_LICENSE}


PERL5_PACKLIST= auto/HTTP/Tiny/Mech/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
