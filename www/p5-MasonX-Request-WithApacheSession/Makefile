# $NetBSD: Makefile,v 1.26 2019/06/30 20:17:39 nia Exp $

DISTNAME=	MasonX-Request-WithApacheSession-0.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MasonX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MasonX-Request-WithApacheSession
COMMENT=	Perl5 module adding a session to the Mason Request obj

DEPENDS+=	p5-Apache-Session-Wrapper>=0.13:../../www/p5-Apache-Session-Wrapper
DEPENDS+=	p5-HTML-Mason>=1.16:../../www/p5-HTML-Mason

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/MasonX/Request/WithApacheSession/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
