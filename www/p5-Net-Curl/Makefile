# $NetBSD: Makefile,v 1.37 2025/01/23 07:12:38 wiz Exp $

DISTNAME=	Net-Curl-0.57
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SY/SYP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Net::Curl
COMMENT=	Perl binding interface for curl
LICENSE=	mit

TOOL_DEPENDS+=	p5-ExtUtils-PkgConfig-[0-9]*:../../devel/p5-ExtUtils-PkgConfig
TEST_DEPENDS+=	p5-Test-CPAN-Meta-[0-9]*:../../devel/p5-Test-CPAN-Meta

CFLAGS+=	-Wall -Werror -Wreturn-type

PERL5_PACKLIST=		auto/Net/Curl/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

USE_TOOLS+=	pkg-config

# self tests hang
# https://github.com/sparky/perl-Net-Curl/issues/78

.include "../../www/curl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
