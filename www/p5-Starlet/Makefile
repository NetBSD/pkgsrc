# $NetBSD: Makefile,v 1.22 2019/08/11 13:24:59 wiz Exp $

DISTNAME=	Starlet-0.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Starlet
COMMENT=	Perl 5 Plack based standalone HTTP/1.0 server
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Starlet/.packlist

BUILD_DEPENDS+=	p5-Test-TCP>=2.10:../../net/p5-Test-TCP
DEPENDS+=	p5-Parallel-Prefork>=0.17:../../devel/p5-Parallel-Prefork
DEPENDS+=	p5-Plack>=0.992:../../www/p5-Plack
DEPENDS+=	p5-Server-Starter>=0.06:../../sysutils/p5-Server-Starter

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
