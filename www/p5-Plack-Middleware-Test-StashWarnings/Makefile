# $NetBSD: Makefile,v 1.3 2013/11/24 09:57:04 wiz Exp $

DISTNAME=	Plack-Middleware-Test-StashWarnings-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Plack/
COMMENT=	TODO: Short description of the package
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	p5-Storable-[0-9]*:../../devel/p5-Storable
DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack

PERL5_PACKLIST=	auto/Plack/Middleware/Test/StashWarnings/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
