# $NetBSD: Makefile,v 1.11 2019/06/30 20:17:42 nia Exp $

DISTNAME=	Plack-Middleware-Test-StashWarnings-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Plack
COMMENT=	TODO: Short description of the package
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	p5-Storable-[0-9]*:../../devel/p5-Storable
DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/Plack/Middleware/Test/StashWarnings/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
