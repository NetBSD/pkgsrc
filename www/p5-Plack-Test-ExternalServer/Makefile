# $NetBSD: Makefile,v 1.17 2023/07/06 09:42:52 wiz Exp $

DISTNAME=	Plack-Test-ExternalServer-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Plack-Test-ExternalServer
COMMENT=	Run HTTP tests on external live servers
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Plack/Test/ExternalServer/.packlist

DEPENDS+=	p5-URI>=0:../../www/p5-URI
DEPENDS+=	p5-libwww>0:../../www/p5-libwww
DEPENDS+=	p5-Plack>=0.9913:../../www/p5-Plack
DEPENDS+=	p5-Test-TCP>0:../../net/p5-Test-TCP
DEPENDS+=	p5-HTTP-Message>=0:../../www/p5-HTTP-Message

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
