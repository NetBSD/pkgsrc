# $NetBSD: Makefile,v 1.12 2022/06/28 11:37:30 wiz Exp $
#

DISTNAME=	HTTP-Server-Simple-Authen-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-Server-Simple-Authen
COMMENT=	Authentication plugin for HTTP::Server::Simple
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Authen-Simple-[0-9]*:../../security/p5-Authen-Simple

REPLACE_PERL=	server.pl

PERL5_PACKLIST=		auto/HTTP/Server/Simple/Authen/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
