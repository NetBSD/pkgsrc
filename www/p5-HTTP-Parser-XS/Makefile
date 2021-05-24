# $NetBSD: Makefile,v 1.19 2021/05/24 19:55:37 wiz Exp $

DISTNAME=	HTTP-Parser-XS-0.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-Parser-XS
COMMENT=	Perl 5 module providing a fast, primitive HTTP request parser
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		c
MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/HTTP/Parser/XS/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
