# $NetBSD: Makefile,v 1.28 2023/11/08 13:21:22 wiz Exp $

DISTNAME=	Net-Curl-0.53
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SY/SYP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Net::Curl
COMMENT=	Perl binding interface for curl
LICENSE=	mit

TEST_DEPENDS+=	p5-Test-CPAN-Meta-[0-9]*:../../devel/p5-Test-CPAN-Meta

CFLAGS+=			-Wall -Werror -Wreturn-type

PERL5_PACKLIST=		auto/Net/Curl/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../www/curl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
