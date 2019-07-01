# $NetBSD: Makefile,v 1.4 2019/07/01 04:08:53 ryoon Exp $

DISTNAME=	Net-Curl-0.39
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SY/SYP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Net::Curl
COMMENT=	Perl binding interface for curl
LICENSE=	mit

BUILDLINK_API_DEPENDS.curl+=	curl>=7.10.8
CFLAGS+=			-Wall -Werror -Wreturn-type

#MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/Net/Curl/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

TEST_DEPENDS+=	p5-Test-CPAN-Meta-[0-9]*:../../devel/p5-Test-CPAN-Meta

.include "../../www/curl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
